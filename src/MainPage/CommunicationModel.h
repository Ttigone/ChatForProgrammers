#ifndef COMMUNICATIONMODEL_H
#define COMMUNICATIONMODEL_H

#include <QAbstractListModel>



class CommunicationModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CommunicationModel(QObject *parent = nullptr);
    ~CommunicationModel();

protected:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


private:
    void init();

private:
};

#endif // COMMUNICATIONMODEL_H
