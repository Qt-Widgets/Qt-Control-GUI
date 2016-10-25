#include <QtGui>

#include <iisVB.h>
#include <iisVBAddons.h>



struct CMeasuringData  
{
	// ��������� �������
	double		Bo;// ������
	double		Ao;// �������
	float		Do;// �������
	long		So;// �������
	int			Lo;// ���� (����� �������)
	int			Type;//��� ������� (0 - ������� 1 - ����, 2 - Cone)
	QString		B_check;
	int			A_check;

	// ������� ���������
	QString		sData;
	QVariant	sMatirial;
	qlonglong	sStandart;
	QString		sAbout;

	// ���������� ������ ��������� ��� ���
	bool		bViewP;
	bool		bViewVP;
	bool		bViewL;
	bool		bViewVL;
	bool		bView_xL;

	// ������ ��� �������
	int			iMaxSpeedLen;
	int			iMaxSpeedP;
	int			ikolef_l;
	int			ikolef_p;

	CMeasuringData()
	{
		Bo = 10;// ������
		Ao = 0;// �������
		Do = 3.890;// �������
		So = 324.0;// �������
		Lo = 12.0;// ���� (����� �������)
		Type = 1;//��� ������� (0 - ������� 1 - ����)
		A_check = Qt::Unchecked;
		B_check = "2";

		sData = "10.12.2003";
		sMatirial = "Metallic E783a";
		sStandart = 90;
		sAbout = "This sample is the specimen of\nMetallic E783a material taken from Mars\nby the NASA's Opportunity rover.";

		bViewP = true;
		bViewVP = true;
		bViewL = false;
		bViewVL = true;
		bView_xL = true;

		iMaxSpeedLen = 0;
		iMaxSpeedP = 20;
		ikolef_l = -12;
		ikolef_p = 555;
	}
};


struct CDrawPlotsSettings
{
	// ������ ��� ������
	int m_nDPI;

	// 1� ������
	// ����������� 1�� �������
	bool m_bDrawPlot1;
	// ����� �� 1� �������
	bool m_bDrawDotsOnPlot1;
	// ���� 1�� �������
	QColor m_colorPlot1;
	// ���� ����� �� 1� �������
	QColor m_colorDotsPlot1;
	// ����������� �������� ������� 1
	QColor m_colorPredPropPlot1;
	QColor m_colorFlowTens1;
	bool m_bDrawLinePredProp1;
	bool m_bDrawFlowTension1;
	bool m_bDrawDotFlowTension1;
	bool m_bDrawFlowTensionPro1;
	bool m_bPrintFlowTens1;
	// �������� ������ �� ������� ������������������
	bool m_bDrawPlotToPP1;

	// 2� ������
	// ����������� 2�� �������
	bool m_bDrawPlot2;
	// ����� �� 2� �������
	bool m_bDrawDotsOnPlot2;
	// ���� 2�� �������
	QColor m_colorPlot2;
	// ���� ����� �� 2� �������
	QColor m_colorDotsPlot2;
	// ����������� �������� ������� 2
	QColor m_colorPredPropPlot2;
	QColor m_colorFlowTens2;
	bool m_bDrawLinePredProp2;
	bool m_bDrawFlowTension2;
	bool m_bDrawDotFlowTension2;
	bool m_bDrawFlowTensionPro2;
	bool m_bPrintFlowTens2;
	// �������� ������ �� ������� ������������������
	bool m_bDrawPlotToPP2;

	// ������ ����� ��� ����������� ����������
	int m_nCalcDotSize;

	// ��� ��������
	QColor m_colorAxisP;
	// ��� ���������� dL
	QColor m_colorAxisDL;
	// ��� ���������� %
	QColor m_colorAxisL;
	// ��� ���������� p/s
	QColor m_colorAxisPS;

	// ���� ��������
	QColor m_colorText;
	// ���� ����
	QColor m_colorBackground;

    // font 1
    QFont m_fFont1;
    // font 2
    QFont m_fFont2;

    QPoint m_pPoint;
    QSize m_pSize;
    QRect m_pRect;
    QPoint m_pRange;


	CDrawPlotsSettings()
	{
		// ��������� �������� �� ���������
		// ������� ���������� ��� �������
		m_bDrawPlot1 = true;
		m_bDrawPlot2 = true;
		// ������ ����� �� ��������
		m_bDrawDotsOnPlot1 = true;
		m_bDrawDotsOnPlot2 = true;
		//����� ��������
		m_colorPlot1 = QColor(0,0,0);
		m_colorPlot2 = QColor(0,0,0);
		// ����� �������� �� ������ ��� ������� ������ ��������
		m_bPrintFlowTens1 = false;
		m_bPrintFlowTens2 = false;
		//����� ����� �� ��������
		m_colorDotsPlot1 = QColor(0,0,0);
		m_colorDotsPlot2 = QColor(0,0,0);
		// �������������� ��������� �� ������� 1
		m_colorPredPropPlot1 = QColor(0,0,255);
		m_colorFlowTens1 = QColor(0,255,0);
		m_bDrawLinePredProp1 = true;
		m_bDrawFlowTension1 = true;
		m_bDrawDotFlowTension1 = true;
		m_bDrawFlowTensionPro1 = true;
		// �������������� ��������� �� ������� 2
		m_colorPredPropPlot2 = QColor(0,0,255);
		m_colorFlowTens2 = QColor(0,255,0);
		m_bDrawLinePredProp2 = true;
		m_bDrawFlowTension2 = true;
		m_bDrawDotFlowTension2 = true;
		m_bDrawFlowTensionPro2 = true;
		// �������� ������ �� ������� ������������������
		m_bDrawPlotToPP1 = false;
		m_bDrawPlotToPP2 = false;

        m_fFont1 = QFont("Helvetica", 10, 50, true);
        m_fFont2 = QFont("Times", 12, 50, false);

        m_pPoint = QPoint(10,40);
        m_pSize = QSize(100,20);
        m_pRect = QRect(m_pPoint, m_pSize);
        m_pRange = QPoint(20,66);
	}
};





class TForm: public QMainWindow
{
Q_OBJECT
public:
    TForm(QWidget *parent = 0) : QMainWindow(parent)
    {
		QWidget *vbox = new QWidget(this);
		setCentralWidget(vbox);
		resize(600,500);

        QHBoxLayout *hbl = new QHBoxLayout(vbox);

		QVBoxLayout *vbl = new QVBoxLayout();
        hbl->addLayout(vbl);

		QTabBar *tw = new QTabBar(vbox);
		tw->addTab("Page 1");
		tw->addTab("Page 2");
		tw->addTab("Page 3");

		vbl->addWidget(tw);


        QSettings::setPath(QSettings::IniFormat, QSettings::UserScope, ".");


		// Value Browser

		m_list = new TValueBrowser(vbox, 22);
		vbl->addWidget(m_list);

		// global special value list
		m_list->setSpecialList(&TValueBrowser::s_specialList);

		// storing policy
		m_list->setStoringPolicy(TValueBrowser::SP_LINKED);

        // section scale
        m_list->setWidthScale(60);



		// add group for sample
		m_list->addGroup("Sample Params", "Sample");

		TItemList *listSampleType = new TItemList;
		*listSampleType << "Box" << "Block" << "Cone" << "Sphere";

		m_list->addList(0, "Sample Type", "", "Type", &m_data.Type, TValueBrowser::LT_UINT, listSampleType);
		m_list->addInt(1, "Length, mm", "", "Length", &m_data.Lo, TValueBrowser::LT_INT);
		m_list->addInt(1, "Slice, mm", "", "Slice", &m_data.So, TValueBrowser::LT_LONG);
		m_list->addReal(0, "Diameter, mm", "", "Diameter", &m_data.Do, TValueBrowser::LT_FLOAT);
		(m_list->addReal(1, "Width, mm", "Width of the sample", "Width", &m_data.Bo))
			->addCheckProperty("WidthCheck", &m_data.B_check, TValueBrowser::LT_STRING);
		(m_list->addReal(2, "Height, mm", "Height of the sample", "Height", &m_data.Ao))
			->addCheckProperty("HeightCheck", &m_data.A_check, TValueBrowser::LT_INT);

		// add group for base params
		m_list->addGroup("Base Params", "Common");

		m_list->addValue(0, "Data", "Data of the sample", "Data", &m_data.sData, TValueBrowser::LT_STRING);
		m_list->addValue(1, "Material", "Base Material", "Material", &m_data.sMatirial, TValueBrowser::LT_VARIANT);
		m_list->addValue(2, "Standart Number", "", "Standart", &m_data.sStandart, TValueBrowser::LT_LONGLONG, TIntValidator::s_IntValidator);
		m_list->addText(0, "Description", "", "About", &m_data.sAbout);

		// add group of view params
		m_list->addGroup("View Params", "View");

		m_list->addBool(0, "P parameter", "", "ViewP", &m_data.bViewP);
		m_list->addBool(1, "VP parameter", "", "ViewVP", &m_data.bViewVP);
		m_list->addBool(2, "L parameter", "", "ViewL", &m_data.bViewL);
		m_list->addBool(3, "VL parameter", "", "ViewVL", &m_data.bViewVL);
		m_list->addBool(1, "xL parameter", "", "ViewXL", &m_data.bView_xL);


		// 2nd Page
		m_list->addPage();

		// add group for 1st graph
		TBaseGroup *g2 = m_list->addGroup("Graph 1", "Graph1");

	        //TFontValue *font1 = new TFontValue(g2, "Font1");



		m_list->addBool(0, "Draw Graph", "", "DrawIt", &m_plots.m_bDrawPlot1);
		(m_list->addColor(1, "Color", "", "Color", &m_plots.m_colorPlot1))->allowListAppending();
		

		m_list->addFont(1, "Font 1", "", "Font1", &m_plots.m_fFont1);
        m_list->addFont(1, "Font 2", "", "Font2", &m_plots.m_fFont2);


        m_list->addPoint(0, "Point", "", "Point", &m_plots.m_pPoint);
        m_list->addSize(0, "Size", "", "Size", &m_plots.m_pSize);
        m_list->addRect(0, "Rect", "", "Rect", &m_plots.m_pRect);
        m_list->addRange(0, "Range", "", "Range", &m_plots.m_pRange);

		TBaseGroup *g3 = m_list->addGroup("Filesystem", "Filesystem");

		TPathValue *pv1 = m_list->addPath(0, "Files only", "", "File", &file1);

		TPathValue *pv2 = m_list->addPath(0, "Directories only", "", "Directory", &file2);
		pv2->setPickMode(QFileDialog::DirectoryOnly);

		TPathValue *pv3 = m_list->addPath(0, "Files of *.txt", "", "TxtFile", &file3);
		pv3->setFilter("*.txt");


		//// 3rd Page
		//m_list->addPage();
		connect( tw, SIGNAL( currentChanged ( int ) ), m_list, SLOT( switchPage( int ) ) );


		// panel
		m_hint = new QLabel(vbox);
		vbl->addWidget(m_hint);
		m_hint->setText("<empty>");
		connect( m_list, SIGNAL(HintChanged(const QString&, TBaseItem*, const QString&)),
			this, SLOT(onHintChanged(const QString&, TBaseItem*, const QString&)) );

		// buttons
		QVBoxLayout *vblb = new QVBoxLayout();
		hbl->addLayout(vblb);


		QPushButton *b4 = new QPushButton("Read", vbox);
		vblb->addWidget(b4);
		connect(b4, SIGNAL(clicked(void)), this, SLOT(onReadItem(void)));

		QPushButton *b5 = new QPushButton("Store", vbox);
		vblb->addWidget(b5);
		connect(b5, SIGNAL(clicked(void)), m_list, SLOT(storeSet(void)));
		QPushButton *b6 = new QPushButton("Restore", vbox);
		vblb->addWidget(b6);
		connect(b6, SIGNAL(clicked(void)), m_list, SLOT(restoreSet(void)));

        vblb->addStretch();

		QPushButton *b7 = new QPushButton("Get Linked", vbox);
		vblb->addWidget(b7);
		connect(b7, SIGNAL(clicked(void)), m_list, SLOT(updateFromLinked(void)));
		QPushButton *b8 = new QPushButton("Set Linked", vbox);
		vblb->addWidget(b8);
		connect(b8, SIGNAL(clicked(void)), m_list, SLOT(updateLinked(void)));


		QPushButton *b9 = new QPushButton("Read Linked", vbox);
		vblb->addWidget(b9);
		connect(b9, SIGNAL(clicked(void)), this, SLOT(onReadSet(void)));
		QPushButton *b2 = new QPushButton("Write Linked", vbox);
		vblb->addWidget(b2);
		connect(b2, SIGNAL(clicked(void)), this, SLOT(onWriteSet(void)));

        vblb->addStretch();


		// after all data have been set, update value browser with linked values 
		m_list->updateFromLinked();
		// and store the set
		m_list->storeSet();
		
	}

public slots:

	void	onReadSet()
	{
		QSettings set("config.ini", QSettings::IniFormat);

		m_list->readDataSet(set);

        m_list->updateFromLinked();

        //m_list->restoreSet();
	}

	void	onWriteSet()
	{
		QSettings set("config.ini", QSettings::IniFormat);

		//m_list->storeSet();

		m_list->updateLinked();

		m_list->writeDataSet(set);
	}

	void	onHintChanged(const QString& hint, TBaseItem *item, const QString& itemName)
	{
		m_hint->setText(QString("<b>%1</b><br>%2").arg(itemName, hint));
	}

	void	onReadItem()
	{
		if (m_list->currentItem()) {
			TBaseItem *bi = (TBaseItem*)(m_list->currentItem());
			if (bi->hasValue()) {
				QString s;
				SValue &v = ((TBaseValue*)bi)->value();
				switch (v.type) {
					case VT_SPECIAL:
						s = "Special";
						break;
					case VT_VALUE:
						s = "Value";
						break;
					case VT_OWN:
						s = "Own";
						break;
				}
				s = tr("The Value of the Item %1 is:\n%2\nValue Type: %3\nItem Type: %4\nCheck State: %5").arg(bi->text(0), v.value.toString(), s, bi->ItemID()).arg(bi->checkState(0));
				QMessageBox::information(this,
					tr("Item Value"), s);
			} else {
				QMessageBox::critical(this,
					tr("Bad Item"),
					tr("Item %1 does not contain a Value").arg(bi->text(0)));
			}
		}
	}

	void	onValuePicked(TBaseItem *bi, const SValue& v)
	{
		QString s;
		//switch (v.type) {
		//	case VT_SPECIAL:
		//		s = tr("%1 (%2)\n(Value Type: Special)").arg(v.idx).arg((*(m_list->specialList()))[v.idx].value.asString());
		//		break;
		//	case VT_VALUE:
		//		s = tr("%1 (index: %2)\n(type: Value)").arg(v.value.toString()).arg(v.idx);
		//		break;
		//	case VT_OWN: 
		//		s = tr("%1\n(type: Own)").arg(v.value.toString());
		//		break;
		//}
		s = tr("The Value of the Item %1 is:\n %2\n(Item Type: %3)").arg(bi->text(1), s, bi->ItemID());
		//if (bi->isChecked())
		//	s += tr("\n([x] Item is On)");
		QMessageBox::information(this,
			tr("Picked Item"), s);
	}


protected:
	QLabel	*m_hint;
	TValueBrowser	*m_list;

	CMeasuringData		m_data;
	CDrawPlotsSettings	m_plots;

	QString file1, file2, file3;
};




int main( int argc, char ** argv )
{
    QApplication a( argc, argv );

	// main window
	TForm w;
    w.setWindowTitle(QString("Value Browser %1 - Linked Values Demo").arg(VB_VERSION_STR));

	// setup
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
	w.show();
    return a.exec();
}

#include "main.moc"