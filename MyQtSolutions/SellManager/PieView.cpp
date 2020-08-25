#include "PieView.h"
#include <QPainter>


PieView::PieView(QWidget *parent)
	: QAbstractItemView(parent)
{
	ui.setupUi(this);
}

PieView::~PieView()
{
}

void PieView::setSelectionModel(QItemSelectionModel * selectionModel)
{
	selections = selectionModel;
}

QRegion PieView::itemRegion(QModelIndex index)
{
	QRegion region;
	if (index.column() == 1)
	{
		region = RegionList[index.row()];
	}
	return region;
}

QRect PieView::visualRect(const QModelIndex & index) const
{
	return QRect();
}

void PieView::scrollTo(const QModelIndex & index, ScrollHint hint)
{
}

QModelIndex PieView::moveCursor(CursorAction cursorAction, Qt::KeyboardModifiers modifiers)
{
	return QModelIndex();
}

int PieView::horizontalOffset() const
{
	return 0;
}

int PieView::verticalOffset() const
{
	return 0;
}

bool PieView::isIndexHidden(const QModelIndex & index) const
{
	return false;
}

void PieView::setSelection(const QRect & rect, QItemSelectionModel::SelectionFlags command)
{
}

QRegion PieView::visualRegionForSelection(const QItemSelection & selection) const
{
	return QRegion();
}

QModelIndex PieView::indexAt(const QPoint & point) const
{
	QPoint newPoint(point.x(), point.y());
	QRegion region;

	foreach(region, RegionList)		//	销售数量一列
	{
		if (region.contains(newPoint))
		{
			int row = RegionList.indexOf(region);
			QModelIndex index = model()->index(row, 1, rootIndex());
			return index;
		}
	}

	return QModelIndex();
}



void PieView::paintEvent(QPaintEvent *)
{
	QPainter painter(viewport());
	painter.setPen(Qt::black);
	int x0 = 40;
	int y0 = 250;

	//y坐标轴
	painter.drawLine(x0, y0, 40, 30);
	painter.drawLine(38, 32, 40, 30);
	painter.drawLine(40, 30, 42, 32);
	painter.drawText(20, 26, QString::fromLocal8Bit("销售数量"));
	for (int i = 1; i < 5; i++)
	{
		painter.drawLine(-1, -i * 50, 1, -i * 50);
		painter.drawText(-20, -i * 50, tr("%1").arg(i * 5));
	}
	//x坐标轴
	painter.drawLine(x0, y0, 420, 250);
	painter.drawLine(418, 248, 420, 250);
	painter.drawLine(420, 250, 418, 252);
	painter.drawText(425, 250, QString::fromLocal8Bit("品牌"));

	int pos = x0 + 20;
	int row;
	for (row = 0; row < model()->rowCount(rootIndex()); row++)
	{
		QModelIndex index = model()->index(row, 0, rootIndex());
		QString dep = model()->data(index).toString();
		painter.drawText(pos, y0 + 20, dep);
		pos += 50;
	}

	int posN = x0 + 20;
	for (row = 0; row < model()->rowCount(rootIndex()); row++)
	{
		QModelIndex index = model()->index(row, 1, rootIndex());
		int sell = model()->data(index).toDouble();

		int width = 10;
		QModelIndex colorIndex = model()->index(row, 0, rootIndex());
		QColor color = QColor(model()->data(colorIndex, Qt::DecorationRole).toString());
		if (selections->isSelected(index))
			painter.setBrush(QBrush(color, Qt::Dense3Pattern));
		else
			painter.setBrush(QBrush(color));

		painter.drawRect(QRect(posN, y0 - sell * 10, width, sell * 10));
		QRegion regionM(posN, y0 - sell * 10, width, sell * 10);
		RegionList << regionM;

		posN += 50;

	}

}
