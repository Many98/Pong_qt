#ifndef TEXT_H
#define TEXT_H

#include <QRect>
#include <QString>
#include <QObject>

class QPainter;
class QTextDocument;
class QGraphicsRectItem;
class QString;
class QGraphicsView;


class Text : public QObject
{
    Q_OBJECT
private:
    QRect *rect;
    QPainter *painter;
    QTextDocument *document;
    QString text="";
    //QGraphicsView *view;
public:
    Text(double x, double y, double w, double h, QString text,QGraphicsView *view);
    ~Text() = default;
    void display();

public slots:
    void changeText();
};

#endif // TEXT_H
