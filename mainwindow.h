#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QAbstractTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:

void convertir();
private:
    Ui::MainWindow *ui;
    QSqlDatabase database;
    double convertLength(double value, const QString &unitFrom, const QString &unitTo);
    double convertedValue;
    void initializeDatabase();
    void showConversionHistory();
    void resetDatabase();
};
class ConversionTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ConversionTableModel(QObject *parent = nullptr);

    void setConversions(const QList<QList<QVariant>>& data);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QList<QList<QVariant>> conversionsData;
};
#endif // MAINWINDOW_H
