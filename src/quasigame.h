/**
 * Copyright (C) 2012 by INdT
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * @author Rodrigo Goncalves de Oliveira <rodrigo.goncalves@openbossa.org>
 * @author Roger Felipe Zanoni da Silva <roger.zanoni@openbossa.org>
 */

#ifndef _QUASIGAME_H_
#define _QUASIGAME_H_

#include "quasideclarativeitem.h"

#include <QtCore/QTime>

class GameScene;
class Viewport;

class QuasiGame : public QuasiDeclarativeItem
{
    Q_OBJECT

    enum { DEFAULT_FPS = 60 };

    Q_PROPERTY(GameScene *currentScene READ currentScene WRITE setCurrentScene NOTIFY currentSceneChanged)
    Q_PROPERTY(int fps READ fps WRITE setFps NOTIFY fpsChanged)
    Q_PROPERTY(QPointF mouse READ mouse)

public:
    QuasiGame(QuasiDeclarativeItem *parent = 0);

    GameScene *currentScene() const;
    void setCurrentScene(GameScene *currentScene);

    int fps() const;
    void setFps(const int &fps);

    QPointF mouse() const;

protected:
    void timerEvent(QTimerEvent *event);
    void update();

signals:
    void currentSceneChanged();
    void fpsChanged();

private:
    GameScene *m_currentScene;
    QTime m_gameTime;
    int m_fps;
    Viewport *m_viewport;
    int m_timerId;
};

#endif /* _QUASIGAME_H_ */
