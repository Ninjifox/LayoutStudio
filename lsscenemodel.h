#ifndef LSSCENEMODEL_H
#define LSSCENEMODEL_H

#include <QAbstractItemModel>
#include <QIcon>
#include "lyt/layout.h"

class LSSceneModel : public QAbstractItemModel {
	Q_OBJECT
public:
	explicit LSSceneModel(LYTLayout *layout, bool exposeVisibility, QObject *parent = 0);
	~LSSceneModel();

	LYTLayout *layout() const { return m_layout; }

	QModelIndex index(int row, int column, const QModelIndex &parent) const;
	QModelIndex parent(const QModelIndex &child) const;
	int rowCount(const QModelIndex &parent) const;
	int columnCount(const QModelIndex &parent) const;
	QVariant data(const QModelIndex &index, int role) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);

	Qt::ItemFlags flags(const QModelIndex &index) const;
	Qt::DropActions supportedDropActions() const;

	bool insertRows(int row, int count, const QModelIndex &parent);
	bool removeRows(int row, int count, const QModelIndex &parent);

private:
	LYTLayout *m_layout;

	QIcon m_paneIcons[LYTPane::PaneTypeCount];

	QPersistentModelIndex *m_movingPaneParent;
	int m_movingPaneRow, m_movingPaneCount;

	bool m_exposesVisibility;
	
signals:
	void paneVisibilityChanged();
	
public slots:
	
};

#endif // LSSCENEMODEL_H
