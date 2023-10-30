#ifndef FILESAVEREADER_H
#define FILESAVEREADER_H

#include <QtGui/QGuiApplication>
#include <QFile>
#include <QTextStream>

class FileSaveReader : public QObject
{
    Q_OBJECT
public:
    FileSaveReader(QObject *parent = 0);
    int cur_state;
    Q_PROPERTY(int cur_state READ get_state WRITE set_state)
    Q_INVOKABLE int get_state();
    Q_INVOKABLE int set_state(int state);
    Q_INVOKABLE void save_state(int state);
    Q_INVOKABLE int load_state();
    ~FileSaveReader();

private:
    QString filename;
};

#endif // FILESAVEREADER_H
