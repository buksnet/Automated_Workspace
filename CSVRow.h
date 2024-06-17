#pragma once
#include <iostream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>

std::vector<std::vector<std::string>> readCSV(QString& filename) {
    std::vector<std::vector<std::string>> table;
    QFile file(filename);
    QTextCodec *codec = QTextCodec::codecForName("unicode");

    if (file.open(QFile::ReadOnly)){
        QTextStream in(&file);
        in.setCodec(codec);
        std::vector<std::string> row;
        while(!in.atEnd()){
            QStringList line = in.readLine().split(',');
            for (QStringList::Iterator i = line.begin(); i != line.end(); i++){
                row.push_back(qPrintable(*i));
            }
            table.push_back(row);
            row.clear();
        }
    }
    file.close();
    return table;
}
