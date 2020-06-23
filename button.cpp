#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>
#include <QFont>
#include <QMediaPlayer>
#include "settings.h"


Button::Button(QString name, QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    //draw the rect
     setRect(0,0,Size::Width/3.85,Size::Height/10.2);
     QBrush brush;
     brush.setStyle(Qt::SolidPattern);
     brush.setColor(Qt::darkMagenta);
     setBrush(brush);

     //draw the text
     text = new QGraphicsTextItem(name,this);
     text->setPos(rect().width()/2 - text->boundingRect().width()/2,
                  rect().height()/2 - text->boundingRect().height()/2);
     text->setFont(QFont("Times", Size::Height/110.0 + Size::Width/192.0, QFont::Bold));

     clickedSound = new QMediaPlayer;
     hoverSound = new QMediaPlayer;
     clickedSound->setMedia(QUrl("qrc:/sounds/decrase.wav"));
     hoverSound->setMedia(QUrl("qrc:/sounds/hover.mp3"));
     setAcceptHoverEvents(true);

}

void Button::resize()
{
    setRect(0,0,Size::Width/3.85,Size::Height/10.2);
    text->setPos(rect().width()/2 - text->boundingRect().width()/2,
                 rect().height()/2 - text->boundingRect().height()/2);
    text->setFont(QFont("Times", Size::Height/110.0 + Size::Width/192.0, QFont::Bold));

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to Magenta

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::magenta);
    setBrush(brush);

    hoverSound->play();
}

void Button::playClickedSound()
{
    clickedSound->play();
}

void Button::mute(int sound)
{
    clickedSound->setVolume(sound);
    hoverSound->setVolume(sound);
}


void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //change color to dark magenta

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);

}
