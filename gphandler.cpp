#include "gphandler.h"
#include <QTextStream>
#include <QDebug>
#include<QFileDialog>
GPHandler::GPHandler(QWidget *parent) :
        QWidget(parent)
{

    tnu=0;
    cgpa=0.0;
    tcp=0;
}

void GPHandler::exportToCSV(void)
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Export as csv file.."),"", tr("CSV files (*.csv)"));
    if (fileName.isEmpty())
        return;
    if (fileName.mid(fileName.size()-4,4) != ".csv")
        fileName = fileName + ".csv";
    QFile data(fileName);
    qDebug()<<" debbug ";
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        QString tcpText=getTCP();
        QString tnuText=getTNU();
        QString  gpaText = getCGP();


        out<< qSetFieldWidth(30) << left <<"COURSE NAMES,"<<"UNIT,"<<"GRADE,"<<endl;

        CourseWeightMapIterator p;

        for(p=gpMap.begin();p!=gpMap.end();++p)
        {
            out<<qSetFieldWidth(0)<<'\n';
            out<<p.key()<<","<<p.value().first<<","<<p.value().second<<endl;
        }
        out<<endl;
        out<<"TOTAL UNITS,"<<"TOTAL POINTS,"<<" GPA, "<<endl;
           out<<tnuText<<","<<tcpText<<","<<gpaText<<endl;

    }

}


void GPHandler::exportToText(void)
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("Export as Text file.."),"", tr("TXT files (*.txt)"));
    if (fileName.isEmpty())
        return;
    if (fileName.mid(fileName.size()-4,4) != ".txt")
        fileName = fileName + ".txt";
    QFile data(fileName);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream out(&data);
        QString tcpText=getTCP();
        QString tnuText=getTNU();
        QString  gpaText = getCGP();


        out<< qSetFieldWidth(30) << left <<"#COURSE NAMES"<< qSetFieldWidth(10) << left <<"UNIT"<<qSetFieldWidth(10) << left<<"GRADE"<<endl;

        CourseWeightMapIterator p;

        for(p=gpMap.begin();p!=gpMap.end();++p)
        {
            out<<qSetFieldWidth(0)<<'\n';
            out<< qSetFieldWidth(30)<<left<<p.key()<<qSetFieldWidth(10)<<left<<p.value().first<<qSetFieldWidth(10)<< left<<p.value().second<<endl;
        }
        out<<qSetFieldWidth(0)<<endl<<endl;
        out<<qSetFieldWidth(20)<<left<<"#TOTAL UNITS"<<qSetFieldWidth(15)<<left<<"TOTAL POINTS"<<qSetFieldWidth(15) << left<<" GPA "<<endl;
        out<<qSetFieldWidth(0)<<endl;
        out<<"#"<<qSetFieldWidth(20)<<left<<tnuText<<qSetFieldWidth(15)<<left<<tcpText<<qSetFieldWidth(15)<<left<<gpaText<<endl;

    }

}
void GPHandler::exportToPdf(void)
{

    QString fileName = QFileDialog::
                       getSaveFileName(this, tr("Export as Pdf.."), "", tr("PDF file (*.pdf"));
//    QString fileName = QFileDialog::getSaveFileName(this,tr("Export as Pdf.."),"", tr("PDF files (*.pdf)"));
    if (fileName.isEmpty())
        return;
    if (fileName.mid(fileName.size()-4,4) != ".pdf")
        fileName = fileName + ".pdf";
    QString html;
    html+=" <table border=\"1\" cellpadding=\"10\"  > <tr align=\"center\">     <th>COURSE NAME</th>      <th>UNIT</th>      <th>GRADE</th>     </tr>";
    CourseWeightMapIterator p;
    short toggle=0;
    for(p=gpMap.begin();p!=gpMap.end();++p)
    {
        QString courseName =p.key();// Qt::escape(p.key());
        QString unit = QString::number(p.value().first,10);
        QString grade = QString::number(p.value().second,10);
        if(toggle^=1){
            html+="<tr bgcolor=\"lightgray\" > <td align=\"left\" >"+courseName+"</td>"
                  +"<td align=\"center\">"+unit+"</td>"
                  +"<td align=\"center\">"+grade+"</td> </tr>";
        }
        else{
            html+="<tr> <td align=\"left\" >"+courseName+"</td>"
                  +"<td align=\"center\">"+unit+"</td>"
                  +"<td align=\"center\">"+grade+"</td> </tr>";
        }
    }
    html+="<tr > <td align=\"center\" >TOTAL UNITS</td>"
          +QString("<td align=\"center\">TOTAL POINTS</td>")
          +QString("<td align=\"center\">GP</td> </tr>");

    QString tcpText=getTCP();
    QString tnuText=getTNU();
    QString  gpaText = getCGP();
    html+="<tr > <td align=\"center\" >"+tnuText+"</td>"
          +"<td align=\"center\">"+tcpText+"</td>"
          +"<td align=\"center\">"+gpaText+"</td> </tr>";
    html+=" </table>\n<br>\n ";
    //qDebug()<<html;
//    QPrinter printer;

//    printer.setOutputFormat(QPrinter::PdfFormat);
//    printer.setOutputFileName(fileName);
//    printer.setFullPage(true);
//    printer.setOrientation(QPrinter::Portrait);
//    printer.setPaperSize(QPrinter::A4);
//    QTextDocument textDocument;
//    textDocument.setHtml(html);
//    textDocument.print(&printer);



}
void GPHandler::updateGP(QString courseName,QString credit, QString grade){

//    qDebug()<<credit<<grade<<courseName;

    credit=credit.left(credit.indexOf("CR")-1);
    bool ok = false;
    int c = credit.toInt(&ok,10);
    if(!ok){
        qDebug()<<credit<<"call it a bug and go home"<<ok;
    }

    if( grade.compare("M",Qt::CaseInsensitive)==0 || grade.compare("S",Qt::CaseInsensitive)==0){
        //special grades
//        enterValues(courseName,c,0);
        return;
    }
    int g = grade.toInt(&ok,10);

    enterValues(courseName,c,g);

}

QString GPHandler::getCGP(){
    QString gpaText;
    QTextStream gpStream(&gpaText);
    gpStream.setRealNumberPrecision(3);
    gpStream<<cgpa;
    return gpaText;

}

QString GPHandler::getTCP(){
    QString tnuText = QString::number(tcp,10);
    return tnuText;

}
QString GPHandler::getTNU(){
    QString tnuText = QString::number(tnu,10);
    return tnuText;

}

void GPHandler::enterValues(QString& cname, int cu, int cg){

    if(!gpMap.contains(cname)){
        QPair<int,int> cu_cgPair;
        cu_cgPair.first=cu;
        cu_cgPair.second=cg;
        gpMap.insert(cname,cu_cgPair);
        no_of_courses++;
        tnu+=cu;
        tcp+=(cu*cg);
        if(tnu==0)cgpa=0.0;
        else cgpa=tcp/(double)tnu;

    }
    else {
        qDebug()<<"same course twice ? scream bug";
    }


}

