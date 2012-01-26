#include "gamescene.h"

#include "quasigame.h"

void GameScene::append_gameItem(QDeclarativeListProperty<GameItem> *list, GameItem *gameItem)
{
    GameScene *scene = qobject_cast<GameScene *>(list->object);
    if (scene) {
        gameItem->setScene(scene);
        gameItem->setParentItem(scene);
        scene->m_entities.append(gameItem);
    }
}

GameScene::GameScene(QuasiGame *parent)
    : QQuickItem(parent)
    , m_running(false)
    , m_collisions(0)
    , m_viewport(0)
    , m_game(0)
    , m_debug(false)
{
    setVisible(false);
}

QDeclarativeListProperty<GameItem> GameScene::entities() const
{
    return QDeclarativeListProperty<GameItem>(const_cast<GameScene *>(this), 0, &GameScene::append_gameItem);
}

void GameScene::update(const long &delta)
{
    if (!m_running) // TODO: stop Qt animations as well
        return;

    checkCollisions();

    GameItem *item;

    foreach (item, m_entities)
        item->update(delta);
}

bool GameScene::running() const
{
    return m_running;
}

void GameScene::setRunning(const bool &running)
{
    if (m_running != running) {
        m_running = running;

        emit runningChanged();
    }
}

void GameScene::checkCollisions()
{
    int itemCount = m_entities.count();

    if (!m_collisions || (m_collisions->count() != itemCount)) {
        if (m_collisions)
            delete [] m_collisions;
        m_collisions = new QVector<QVector<bool> >(itemCount, QVector<bool>(itemCount));
    }

    GameItem *item, *otherItem;

    foreach (item, m_entities)
        item->setCollided(false);

    for (int i = 0; i < itemCount; ++i) {
        item = m_entities.at(i);
        for (int j = 0; j < itemCount; ++j) {
            if (i == j)
                continue;

            otherItem = m_entities.at(j);

            bool collided = checkCollision(item, otherItem);

            item->setCollided(item->collided() ? true : collided);
            otherItem->setCollided(otherItem->collided() ? true : collided);

            (*m_collisions)[i][j] = collided;
            (*m_collisions)[j][i] = collided;
        }
    }
}

bool GameScene::checkCollision(GameItem *item, GameItem *otherItem) const
{
    QRectF itemRect = item->boundingRect();
    QRectF otherItemRect = otherItem->boundingRect();

    itemRect.moveTo(item->x(), item->y());
    otherItemRect.moveTo(otherItem->x(), otherItem->y());

    return itemRect.intersects(otherItemRect)
           || itemRect.contains(otherItemRect)
           || otherItemRect.contains(itemRect);
}

QList<QObject *> GameScene::collidedItems(GameItem *gameItem) const
{
    QList<QObject *> collidedItemsList;

    if (m_collisions) {
        int index = m_entities.indexOf(gameItem);

        if (index != -1) {
            for (int i=0; i < m_entities.size(); ++i) {
                if (i != index && (*m_collisions)[index][i]) {
                    collidedItemsList.append(m_entities.at(i));
                }
            }
        }
    }

    return collidedItemsList;
}

Viewport *GameScene::viewport() const
{
    return m_viewport;
}

void GameScene::setViewport(Viewport *viewport)
{
    if (m_viewport != viewport) {
        m_viewport = viewport;

        emit viewportChanged();
    }
}

QuasiGame *GameScene::game() const
{
    return m_game;
}

void GameScene::setGame(QuasiGame *game)
{
    m_game = game;
}

bool GameScene::debug() const
{
    return m_debug;
}

void GameScene::setDebug(const bool &debug)
{
    if (m_debug != debug) {
        m_debug = debug;

        emit debugChanged();
    }
}
