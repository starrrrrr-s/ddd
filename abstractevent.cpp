#include "abstractevent.h"
#include "recurrentevent.h"
#include "continuousevent.h"

#include <QDir>
#include <QMessageBox>
//抽象事件类
AbstractEvent::AbstractEvent(const QDate& begin, const QDate& end) :
    begin(begin), end(end),
    magic_string(QString("%1%2").arg(qrand() % 32768).arg(qrand() % 32768))
{

}

AbstractEvent::~AbstractEvent()
{

}
//获取文件
QString AbstractEvent::FilePathAt(int i) const
{
    QString dir = Const::DISK_DIR + "event_" + magic_string;
    return QDir::currentPath() + "/" + dir + "/" + file_name_list[i];
}
//删除单个文件
void AbstractEvent::RemoveFile(const QString& fileName)
{
    QString dir = Const::DISK_DIR + "event_" + magic_string;
    QFile(QDir::currentPath() + "/" + dir + "/" + fileName).remove();
    for (auto i = file_name_list.begin(); i != file_name_list.end(); i++)
        if (QFileInfo(*i).fileName() == fileName)
        {
            file_name_list.erase(i);
            break;
        }
}
//删除所有文件
void AbstractEvent::RemoveAllFiles()
{
    QString dir = Const::DISK_DIR + "event_" + magic_string;
    QDir(QDir::currentPath() + "/" + dir).removeRecursively();
    file_name_list.clear();
}
//赋值
void AbstractEvent::Clone(AbstractEvent *event)
{
    begin = event->begin;
    end = event->end;
    title = event->title;
    place = event->place;
    detail = event->detail;
    magic_string = event->magic_string;
    color = event->color;
    file_name_list = event->file_name_list;
}
//添加文件
bool AbstractEvent::AddFile(const QString &filePath, QWidget* parent)
{
    QString dir = Const::DISK_DIR + "event_" + magic_string;
    if (!QDir(dir).exists()) QDir::current().mkpath(dir);

    QString fileName = QFileInfo(filePath).fileName();
    QString newFilePath = QDir::currentPath() + "/" + dir + "/" + fileName;
    if (QFile(newFilePath).exists())
    {
        QMessageBox::critical(parent, tr("Import File Failed"), QString(tr("The file \"%1\" is already in this event!")).arg(fileName));
        return false;
    }
    if (QFile::copy(filePath, newFilePath))
    {
        file_name_list.push_back(fileName);
        QMessageBox::information(parent, tr("File Imported Successfully"), QString(tr("Successfully imported the file \"%1\".")).arg(fileName));
        return true;
    }
    return false;
}

//写入文件
QDataStream& operator <<(QDataStream& dataStream, AbstractEvent* event)
{
    dataStream << (int)event->Type();
    dataStream << event->begin << event->end;
    dataStream << event->title << event->place << event->detail << event->magic_string;
    dataStream << event->color;
    dataStream << event->file_name_list;
    event->save(dataStream);
    return dataStream;
}
//读取文件
QDataStream& operator >>(QDataStream& dataStream, AbstractEvent** event)
{
    int type;
    QDate begin, end;
    AbstractEvent* aevent;
    dataStream >> type >> begin >> end;
    if ((AbstractEvent::EventType)type == AbstractEvent::ContinuousEvent)
        aevent = new ContinuousEvent(begin, end);
    else if ((AbstractEvent::EventType)type == AbstractEvent::RecurrentEvent)
        aevent = new RecurrentEvent(begin, end);
    else
        return dataStream;

    dataStream >> aevent->title >> aevent->place >> aevent->detail >> aevent->magic_string;
    dataStream >> aevent->color;
    dataStream >> aevent->file_name_list;
    aevent->load(dataStream);
    *event = aevent;
    return dataStream;
}
