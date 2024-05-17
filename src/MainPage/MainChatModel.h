#ifndef MAINCHATMODEL_H
#define MAINCHATMODEL_H

#include <QAbstractListModel>
#include <map>

class CellData;


class MainChatModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MainChatModel(QObject *parent = nullptr);
    ~MainChatModel();

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;

private:
    void init();

    std::map<int64_t, CellData> m_userMap;
};

#endif // MAINCHATMODEL_H
