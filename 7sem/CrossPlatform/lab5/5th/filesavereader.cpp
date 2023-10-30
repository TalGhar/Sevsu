#include "filesavereader.h"

FileSaveReader::FileSaveReader(QObject *parent):
    QObject(parent)
{
    this->filename = QString("state.txt");
}

FileSaveReader::~FileSaveReader()
{
}

int FileSaveReader::get_state()
{
    return cur_state;
}

int FileSaveReader::set_state(int state)
{
    cur_state = state;
    return cur_state;
}

int FileSaveReader::load_state()
{
    QFile file(filename);
    if (file.open(QFile::ReadWrite))
    {
        QTextStream in_stream(&file);
        cur_state = in_stream.readAll().toInt();
    }
    file.close();
    return cur_state;
}

void FileSaveReader::save_state(int state)
{
    QFile file(filename);
    if (file.open(QFile::ReadWrite | QIODevice::Truncate))
    {
        QTextStream in_stream(&file);
        QTextStream out_stream(&file);
        out_stream << cur_state;
    }
    file.close();
}

