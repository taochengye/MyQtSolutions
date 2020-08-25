#pragma once

#include <QAbstractItemView>
#include "ui_PieView.h"



class PieView : public QAbstractItemView
{
	Q_OBJECT

public:
	PieView(QWidget *parent = Q_NULLPTR);
	~PieView();

	//Îªselections¸³³õÖµ
	void setSelectionModel(QItemSelectionModel * selectionModel);
	QRegion itemRegion(QModelIndex index);

	QRect visualRect(const QModelIndex &index) const;
	void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
	QModelIndex indexAt(const QPoint &point) const;
	QModelIndex moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers);
	int horizontalOffset() const;
	int verticalOffset() const;
	
	bool isIndexHidden(const QModelIndex &index) const;
	void setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags command);
	QRegion visualRegionForSelection(const QItemSelection &selection) const;


signals:

public slots:


private:
	Ui::PieView ui;
	
	QItemSelectionModel *selections;
	QList<QRegion> RegionList;


protected:
	void paintEvent(QPaintEvent *);

};
