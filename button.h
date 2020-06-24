#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class QGraphicsTextItem;
class QFont;
class QString;
class QMediaPlayer;

class Button : public QObject, public QGraphicsRectItem
{
   Q_OBJECT
private:
    QGraphicsTextItem *text;
    QMediaPlayer *clickedSound, *hoverSound;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

public:
    Button(QString name, QGraphicsItem *parent = nullptr);
    ~Button() = default;
    void resize();
    void mute(int sound);

public slots:
    void playClickedSound();

signals:
    void clicked();
};
#endif // BUTTON_H
