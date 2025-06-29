/* in file ham marbot be class playlist hast ke function hay mord estefade dar on gharar darad
*/


#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QAbstractItemModel>

class QMediaPlaylist;

class playlist: public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Column
    {
        Title = 0,
        ColumnCount
    };

    playlist(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    QMediaPlaylist *playlis() const;
    void setPlaylist(QMediaPlaylist *playlis);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);

private:
    QMediaPlaylist *m_playlist;
    QMap<QModelIndex, QVariant> m_data;
};

#endif // PLAYLIST_H
