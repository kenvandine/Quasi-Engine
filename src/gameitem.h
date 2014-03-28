#ifndef _GAMEITEM_H_
#define _GAMEITEM_H_

#include <QTime>
#include <QtQuick/QQuickItem>
#include <QDeclarativeScriptString>

class QDeclarativeExpression;
class QuasiGame;
class GameScene;

class GameItem : public QQuickItem
{
    Q_OBJECT

    Q_PROPERTY(QDeclarativeScriptString updateScript READ updateScript WRITE setUpdateScript NOTIFY updateScriptChanged)
    Q_PROPERTY(int updateInterval READ updateInterval WRITE setUpdateInterval NOTIFY updateIntervalChanged)
    Q_PROPERTY(bool collided READ collided WRITE setCollided NOTIFY collidedChanged)
    Q_PROPERTY(QuasiGame *game READ game)

public:
    GameItem(GameScene *parent = 0);

    QDeclarativeScriptString updateScript() const;
    void setUpdateScript(const QDeclarativeScriptString &updateScript);

    int updateInterval() const;
    void setUpdateInterval(const int &updateInterval);

    bool collided() const;
    void setCollided(const bool &collided);

    Q_INVOKABLE QList<QObject *> collidedItems() const;

    GameScene *scene() const;
    void setScene(GameScene *scene);

    QuasiGame *game() const;

    virtual void update(const long &delta);

signals:
    void updateScriptChanged();
    void updateIntervalChanged();
    void collidedChanged();

private:
    QDeclarativeScriptString m_updateScript;
    QDeclarativeExpression *m_expression;
    int m_updateInterval;
    QTime m_updateTime;
    bool m_collided;
    GameScene *m_scene;
};

#endif /* _GAMEITEM_H_ */
