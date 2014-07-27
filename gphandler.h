#ifndef GPHANDLER_H
#define GPHANDLER_H

#include <QMap>
#include <QPair>
#include <QObject>

#include <QMap>
#include <QPair>
#include <QTextStream>
#include <QVariant>
#include<QMessageBox>
#include<QFileDialog>
#include <QColor>
//#include <QPrinter>
#include <QPainter>
#include "exportoption.h"
#include "QTextDocument"

typedef QMap<QString, QPair<int,int> > CourseWeightMap;
typedef CourseWeightMap::iterator CourseWeightMapIterator;
class GPHandler : public QWidget
{
    Q_OBJECT
public:
    explicit GPHandler(QWidget *parent = 0);
    void updateGP(QString courseName,QString credit, QString grade);
    QString getTNU();
    QString getTCP();
    QString getCGP();
    int getCoursesCount();
    void exportToPdf();
    void exportToText(void);
    void  exportToCSV(void);
signals:

private:
    int tnu,tcp;
    float cgpa;
    int no_of_courses;
    void enterValues(QString& cname, int cu, int cg);
    CourseWeightMap gpMap;
    //    ExportOption exportOption;

public slots:

};

#endif // GPHANDLER_H
