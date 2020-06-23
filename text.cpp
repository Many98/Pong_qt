#include "text.h"
#include <QPainter>
#include <QTextDocument>
#include <QRect>
#include <QFont>
#include <QGraphicsView>


Text::Text(double x, double y, double w, double h, QString text,QGraphicsView *view)
    :rect(new QRect(x,y,w,h)), painter(new QPainter(view)), document(new QTextDocument),
      text(text)
{
    painter->setFont(QFont("Times", 16, QFont::Bold));
}

void Text::display()
{
    painter->drawText(*rect,text);

}

void Text::changeText()
{

}
