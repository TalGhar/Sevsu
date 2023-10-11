#ifndef LABEL_H
#define LABEL_H

#include <QLabel>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent);
signals:
    void isLimit();

};

#endif // LABEL_H
