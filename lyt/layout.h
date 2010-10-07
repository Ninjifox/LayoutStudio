#ifndef LYTLAYOUT_H
#define LYTLAYOUT_H

#include "packagebase.h"
#include "materials/material.h"
#include "group.h"
#include "pane.h"
#include "textbox.h"
#include "picture.h"
#include "window.h"
#include "bounding.h"
#include "binaryfile.h"
#include "binaryfilesection.h"

#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtCore/QDataStream>

class LYTTexMap; // forward declaration so it can be a friend class

class LYTLayout {
public:
	LYTLayout(LYTPackageBase &package);
	LYTLayout(LYTPackageBase &package, QString name);
	~LYTLayout();

	void clear();
	LYTPackageBase &package() const;

	float width;
	float height;

	QMap<QString, LYTMaterial *> materials;

	LYTPane *rootPane;
	QList<LYTGroup *> groups;



protected:
	LYTPackageBase &m_package;

	// these are private because they are not intended for public use
	// they're only here so that LYTPane's subclasses and a few others can read
	// this info when reading/writing -- hence why they are friend classes
	QStringList m_fontRefs;
	QStringList m_textureRefs;

	bool loadLayoutFromPackage(QString name);

	void readLyt1(LYTBinaryFileSection &section);
	void readTxl1(LYTBinaryFileSection &section);
	void readFnl1(LYTBinaryFileSection &section);
	void readMat1(LYTBinaryFileSection &section);

	LYTPane *createPaneObj(LYTBinaryFileSection &section);

	friend class LYTPane;
	friend class LYTTextBox;
	friend class LYTPicture;
	friend class LYTWindow;
	friend class LYTBounding;
	friend class LYTTexMap;

};

#endif // LYTLAYOUT_H
