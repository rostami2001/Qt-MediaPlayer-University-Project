/* dar in file tanzimat radif ha va soton ha va gharar gereftan har data dar makan dorost
 * ba ezafe shodam file jadid ya remove shodan file baghie data ha dar makan dorost gharar begirand
*/

#include "playlist.h"
#include "ui_playlist.h"

#include <QFileInfo>
#include <QUrl>
#include <QMediaPlaylist>

playlist::playlist(QObject *parent)
    : QAbstractItemModel(parent)
    , m_playlist(0)
{
}


int playlist::rowCount(const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid() ? m_playlist->mediaCount() : 0;
}

int playlist::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? ColumnCount : 0;
}


QModelIndex playlist::index(int row, int column, const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid()
            && row >= 0 && row < m_playlist->mediaCount()
            && column >= 0 && column < ColumnCount
        ? createIndex(row, column)
        : QModelIndex();
}

QModelIndex playlist::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

QVariant playlist::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = m_data[index];
        if (!value.isValid() && index.column() == Title) {
            QUrl location = m_playlist->media(index.row()).canonicalUrl();
            return QFileInfo(location.path()).fileName();
        }

        return value;
    }
    return QVariant();
}

QMediaPlaylist *playlist::playlis() const
{
    return m_playlist;
}

void playlist::setPlaylist(QMediaPlaylist *playlis)
{
    if (m_playlist) {
        disconnect(m_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        disconnect(m_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        disconnect(m_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        disconnect(m_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        disconnect(m_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }

    beginResetModel();
    m_playlist = playlis;

    if (m_playlist) {
        connect(m_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        connect(m_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        connect(m_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        connect(m_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        connect(m_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }

    endResetModel();
}

bool playlist::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    m_data[index] = value;
    emit dataChanged(index, index);
    return true;
}

void playlist::beginInsertItems(int start, int end)
{
    m_data.clear();
    beginInsertRows(QModelIndex(), start, end);
}

void playlist::endInsertItems()
{
    endInsertRows();
}

void playlist::beginRemoveItems(int start, int end)
{
    m_data.clear();
    beginRemoveRows(QModelIndex(), start, end);
}

void playlist::endRemoveItems()
{
    endInsertRows();
}

void playlist::changeItems(int start, int end)
{
    m_data.clear();
    emit dataChanged(index(start,0), index(end,ColumnCount));
}
