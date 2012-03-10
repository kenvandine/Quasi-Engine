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

#include "spritesheet.h"

#include <QtGui/QPixmap>
#include <QtGui/QPainter>
#include <QDeclarativeProperty>

SpriteSheet::SpriteSheet(QuasiDeclarativeItem *parent)
    : QuasiPaintedItem(parent)
    , m_pixMap(0)
    , m_frames(0)
    , m_frame(0)
    , m_initialFrame(0)
    , m_frameWidth(0)
{
    setVisible(false);

    QDeclarativeProperty(this, "layer.enabled").write(true);
}

QString SpriteSheet::source() const
{
    return m_source;
}

void SpriteSheet::setSource(const QString &source)
{
    if (m_source != source) {
        if (m_pixMap)
            delete m_pixMap;

        m_source = source;

        m_pixMap = new QPixmap(m_source);

        if (m_frames)
            updateSizeInfo();

        update();

        emit sourceChanged();
    }
}

#if QT_VERSION >= 0x050000
void SpriteSheet::paint(QPainter *painter)
#else
void SpriteSheet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
#endif
{
    if (m_pixMap) {
        if (!m_frames)
            painter->drawPixmap(0, 0, *m_pixMap);
        else
            painter->drawPixmap(0, 0, *m_pixMap, (m_frame * m_frameWidth), 0, m_frameWidth, m_pixMap->height());
    }
}

int SpriteSheet::frames() const
{
    return m_frames;
}

void SpriteSheet::setFrames(const int &frames)
{
    if (m_frames != frames) {
        m_frames = frames;

        if (m_pixMap)
            updateSizeInfo();

        update();

        emit framesChanged();
    }
}

int SpriteSheet::frame() const
{
    return m_frame;
}

void SpriteSheet::setFrame(const int &frame)
{
    if (m_frame != frame
        && frame < m_frames) { //FIXME: using qt5 and non infinite animations, the property animation updates this value to m_frames, the max should be m_frames-1
        m_frame = frame;

        update();

        emit frameChanged();
    }
}

void SpriteSheet::updateSizeInfo()
{
    m_frameWidth = m_pixMap->width() / m_frames;
    setWidth(m_frameWidth);
    setHeight(m_pixMap->height());
}

int SpriteSheet::initialFrame() const
{
    return m_initialFrame;
}

void SpriteSheet::setInitialFrame(const int &initialFrame)
{
    if (m_initialFrame != initialFrame) {
        m_initialFrame = initialFrame;

        emit initialFrameChanged();
    }
}
