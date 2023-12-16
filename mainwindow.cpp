#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>
#include<QDialog>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonconvertir,&QPushButton::clicked,this,&MainWindow::convertir);

    connect(ui->actionAfficher_l_historique, &QAction::triggered, this, &MainWindow::showConversionHistory);

    connect(ui->actionR_initialiser_l_historique, &QAction::triggered, this, &MainWindow::resetDatabase);

    connect(ui->pushButtonquitter,&QPushButton::clicked,this,&MainWindow::close);

     initializeDatabase();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initializeDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("conversions.db");

    if (!db.open()) {
        qDebug() << "Erreur : Impossible d'ouvrir la base de données.";
        return;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS conversions (id INTEGER PRIMARY KEY AUTOINCREMENT, value_from TEXT, unit_from TEXT, value_to TEXT, unit_to TEXT)");
}

double MainWindow::convertLength(double value, const QString &unitFrom, const QString &unitTo) {
    // Les formules de conversion pour différentes unités de longueur
    const double ligne_to_pied =0.0069;
    const double pouce_to_pied =0.0834;
    const double pied_to_pied=1;
    const double yard_to_pied=3;
    const double mile_to_pied=5280;
    const double centimetre_to_pied=0.032;
    const double metre_to_pied=3.281;
    const double kilometre_to_pied=3281;
    const double millimetre_to_pied=0.00328;
    double result =value;
//unité d'entée ligne
        if (unitFrom == "Ligne"&& unitTo =="Pied") {
            result= (result *ligne_to_pied)/pied_to_pied; ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Pouce")
        {
            result= (result *ligne_to_pied)/pouce_to_pied ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Yard")
        {
            result= (result *ligne_to_pied)/yard_to_pied ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Mille")
        {
            result= (result *ligne_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Centimètre")
        {
            result= (result *ligne_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Mètre")
        {
            result= (result *ligne_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Kilomètre")
        {
            result= (result *ligne_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="Millimètre")
        {
            result= (result *ligne_to_pied)/millimetre_to_pied; ;
        }
        else if (unitFrom == "Ligne"&& unitTo =="ligne")
        {
            result= result*1;
        }

   //unité d'entée Pouce
        if (unitFrom == "Pouce"&& unitTo =="Pied") {
            result= (result *pouce_to_pied)/pied_to_pied; ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Pouce")
        {
            result= (result *pouce_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Yard")
        {
            result= (result *pouce_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Mille")
        {
            result= (result *pouce_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Centimètre")
        {
            result= (result *pouce_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Mètre")
        {
            result= (result *pouce_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Kilomètre")
        {
            result= (result *pouce_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Millimètre")
        {
            result= (result *pouce_to_pied)/millimetre_to_pied; ;
        }
        else if (unitFrom == "Pouce"&& unitTo =="Ligne")
        {
            result= (result *pouce_to_pied)/ligne_to_pied ;
        }
     //Unité d'entré yard
        if (unitFrom == "Yard"&& unitTo =="Pied") {
            result= (result *yard_to_pied)/pied_to_pied; ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Pouce")
        {
            result= (result *yard_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Yard")
        {
            result= (result *yard_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Mille")
        {
            result= (result *yard_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Centimètre")
        {
            result= (result *yard_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Mètre")
        {
            result= (result *yard_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Yard"&& unitTo =="Kilomètre")
        {
            result= (result *yard_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Millimètre")
        {
            result= (result *yard_to_pied)/millimetre_to_pied; ;
        }
        else if (unitFrom == "Yard"&& unitTo =="Ligne")
        {
            result= (result *yard_to_pied)/ligne_to_pied ;
        }
    //Unite d'entré mile
        if (unitFrom == "Mille"&& unitTo =="Pied") {
            result= (result *mile_to_pied )/pied_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Pouce")
        {
            result= (result *mile_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Yard")
        {
            result= (result *mile_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Mille")
        {
            result= (result *mile_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Centimètre")
        {
            result= (result *mile_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Mètre")
        {
            result= (result *mile_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Mille"&& unitTo =="Kilomètre")
        {
            result= (result *mile_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Millimètre")
        {
            result= (result *mile_to_pied)/millimetre_to_pied ;
        }
        else if (unitFrom == "Mille"&& unitTo =="Ligne")
        {
            result= (result *mile_to_pied)/ligne_to_pied ;
        }
   //Unité d'entre Pied
        if (unitFrom == "Pied"&& unitTo =="Pied") {
            result= (result)/pied_to_pied; ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Pouce")
        {
            result= (result)/pouce_to_pied ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Yard")
        {
            result= (result)/yard_to_pied ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Mille")
        {
            result= (result)/mile_to_pied; ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Centimètre")
        {
            result= (result)/centimetre_to_pied ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Mètre")
        {
            result= (result)/metre_to_pied;
        }
        else if (unitFrom == "Pied"&& unitTo =="Kilomètre")
        {
            result= (result)/kilometre_to_pied ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Millimètre")
        {
            result= (result)/millimetre_to_pied; ;
        }
        else if (unitFrom == "Pied"&& unitTo =="Ligne")
        {
            result= (result)/ligne_to_pied ;
        }
   //Unite entré millimetre                                                                                                                                  dossouPerseverance
        if (unitFrom == "Millimètre"&& unitTo =="Pied") {
            result= (result *millimetre_to_pied)/pied_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Pouce")
        {
            result= (result *millimetre_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Yard")
        {
            result= (result *millimetre_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Mille")
        {
            result= (result *millimetre_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Centimètre")
        {
            result= (result *millimetre_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Mètre")
        {
            result= (result *millimetre_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Kilomètre")
        {
            result= (result *millimetre_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Millimètre")
        {
            result= (result *millimetre_to_pied)/millimetre_to_pied ;
        }
        else if (unitFrom == "Millimètre"&& unitTo =="Ligne")
        {
            result= (result *millimetre_to_pied)/ligne_to_pied ;
        }
   // Unite entré centimetre
        if (unitFrom == "Centimètre"&& unitTo =="Pied") {
            result= (result *centimetre_to_pied)/pied_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Pouce")
        {
            result= (result *centimetre_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Yard")
        {
            result= (result *centimetre_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Mille")
        {
            result= (result *centimetre_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Centimètre")
        {
            result= (result *centimetre_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Mètre")
        {
            result= (result *centimetre_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Kilomètre")
        {
            result= (result *centimetre_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Millimètre")
        {
            result= (result *centimetre_to_pied)/millimetre_to_pied ;
        }
        else if (unitFrom == "Centimètre"&& unitTo =="Ligne")
        {
            result= (result *centimetre_to_pied)/ligne_to_pied ;
        }
    //unite entre metre
        if (unitFrom == "Mètre"&& unitTo =="Pied") {
            result= (result *metre_to_pied)/pied_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Pouce")
        {
            result= (result *metre_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Yard")
        {
            result= (result *metre_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Mille")
        {
            result= (result *metre_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Centimètre")
        {
            result= (result *metre_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Mètre")
        {
            result= (result *metre_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Kilomètre")
        {
            result= (result *metre_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Millimètre")
        {
            result= (result *metre_to_pied)/millimetre_to_pied ;
        }
        else if (unitFrom == "Mètre"&& unitTo =="Ligne")
        {
            result= (result *metre_to_pied)/ligne_to_pied ;
        }
   //Unité entre Kilometre
        if (unitFrom == "Kilomètre"&& unitTo =="Pied") {
            result= (result *kilometre_to_pied)/pied_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Pouce")
        {
            result= (result *kilometre_to_pied )/pouce_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Yard")
        {
            result= (result *kilometre_to_pied )/yard_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Mille")
        {
            result= (result *kilometre_to_pied)/mile_to_pied; ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Centimètre")
        {
            result= (result *kilometre_to_pied)/centimetre_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Mètre")
        {
            result= (result *kilometre_to_pied)/metre_to_pied;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Kilomètre")
        {
            result= (result *kilometre_to_pied)/kilometre_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Millimètre")
        {
            result= (result *kilometre_to_pied)/millimetre_to_pied ;
        }
        else if (unitFrom == "Kilomètre"&& unitTo =="Ligne")
        {
            result= (result *kilometre_to_pied)/ligne_to_pied ;
        }

                return result;
               }


void MainWindow::convertir() {
    double inputValue = ui-> lineEditValue->text().toDouble();
    QString unitFrom =ui-> comboBoxUnitFrom->currentText();
    QString unitTo =ui-> comboBoxUnitTo->currentText();

    double convertedValue = convertLength(inputValue, unitFrom, unitTo);

             ui-> textBrowserResult->setText(QString::number(convertedValue));
             // Enregistrer la conversion dans la base de données
                 QSqlQuery query;
                 query.prepare("INSERT INTO conversions (value_from, unit_from, value_to, unit_to) VALUES (?, ?, ?, ?)");
                 query.addBindValue(inputValue);
                 query.addBindValue(unitFrom);
                 query.addBindValue(convertedValue);
                 query.addBindValue(unitTo);
                 if (!query.exec()) {
                         qDebug() << "Erreur lors de l'enregistrement dans la base de données:" << query.lastError().text();
                 }
}

ConversionTableModel::ConversionTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void ConversionTableModel::setConversions(const QList<QList<QVariant>>& data) {
    beginResetModel();
    conversionsData = data;
    endResetModel();
}

int ConversionTableModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return conversionsData.size();
}

int ConversionTableModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return 4; // 4 colonnes : value_from, unit_from, value_to, unit_to
}

QVariant ConversionTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        int row = index.row();
        int col = index.column();
        return conversionsData[row][col];
    }

    return QVariant();
}

QVariant ConversionTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Value From");
        case 1:
            return tr("Unit From");
        case 2:
            return tr("Value To");
        case 3:
            return tr("Unit To");
        default:
            return QVariant();
        }
    }

    return QVariant();
}
void MainWindow::showConversionHistory() {
    // Récupérer les enregistrements de la base de données
    QSqlQuery query("SELECT value_from, unit_from, value_to, unit_to FROM conversions");
    QList<QList<QVariant>> conversionsData;

    while (query.next()) {
        QList<QVariant> row;
        row.append(query.value("value_from"));
        row.append(query.value("unit_from"));
        row.append(query.value("value_to"));
        row.append(query.value("unit_to"));
        conversionsData.append(row);
    }

    // Créer le modèle
    ConversionTableModel *model = new ConversionTableModel(this);
    model->setConversions(conversionsData);


    QTableView *tableViewHistory = new QTableView(this);
    tableViewHistory->setModel(model);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(tableViewHistory);

    QDialog *historyDialog = new QDialog(this);
    historyDialog->setLayout(layout);
    historyDialog->resize(400, 300);
    historyDialog->exec(); // Afficher la fenêtre de dialogue

}
void MainWindow::resetDatabase() {
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS conversions");
    query.exec("CREATE TABLE conversions (id INTEGER PRIMARY KEY AUTOINCREMENT, value_from REAL, unit_from TEXT, value_to REAL, unit_to TEXT)");
}
