#pragma once
#include "BinaryHeap.h"
#include "LinkedList.h"
#include "Graham.h"
#include <msclr\marshal_cppstd.h>
#include "Kruskal.h"
#include "TimeStruct.h"
#include <math.h>
#include <vector>
#include <fstream>

namespace GrahamVisualized {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using std::vector;

	std::string filePath;
	std::string saveFilePath;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			GrahamChart->Series->Clear();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ GrahamChart;

	private: System::Windows::Forms::Button^ chooseFileButton;
	private: System::Windows::Forms::Button^ grahamButton;
	private: System::Windows::Forms::Button^ kruskalButton;
	private: System::Windows::Forms::TabControl^ tabControlStats;
	private: System::Windows::Forms::TabPage^ tabPageStats;
	private: System::Windows::Forms::TabPage^ tabPageNewFile;
	private: System::Windows::Forms::Label^ statLabel1;
	private: System::Windows::Forms::Label^ statLabel3;

	private: System::Windows::Forms::Label^ statLabel2;
	private: System::Windows::Forms::ListBox^ statListBox;

	private: System::Windows::Forms::Label^ statLabel4;
	private: System::Windows::Forms::Button^ saveFileLocationButton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ saveFileButton;
	private: System::Windows::Forms::ListBox^ listBoxEdges;
	private: System::Windows::Forms::Button^ addEdgeButton;
	private: System::Windows::Forms::TextBox^ textBoxEdgeY;

	private: System::Windows::Forms::TextBox^ textBoxEdgeX;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ListBox^ listBoxPoints;
	private: System::Windows::Forms::Button^ addPointButton;
	private: System::Windows::Forms::TextBox^ textBoxPointY;

	private: System::Windows::Forms::TextBox^ textBoxPointX;
	private: System::Windows::Forms::Button^ deleteEdgeButton;
	private: System::Windows::Forms::Button^ deletePointButton;










	protected:
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->GrahamChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chooseFileButton = (gcnew System::Windows::Forms::Button());
			this->grahamButton = (gcnew System::Windows::Forms::Button());
			this->kruskalButton = (gcnew System::Windows::Forms::Button());
			this->tabControlStats = (gcnew System::Windows::Forms::TabControl());
			this->tabPageStats = (gcnew System::Windows::Forms::TabPage());
			this->statLabel4 = (gcnew System::Windows::Forms::Label());
			this->statListBox = (gcnew System::Windows::Forms::ListBox());
			this->statLabel3 = (gcnew System::Windows::Forms::Label());
			this->statLabel2 = (gcnew System::Windows::Forms::Label());
			this->statLabel1 = (gcnew System::Windows::Forms::Label());
			this->tabPageNewFile = (gcnew System::Windows::Forms::TabPage());
			this->deleteEdgeButton = (gcnew System::Windows::Forms::Button());
			this->deletePointButton = (gcnew System::Windows::Forms::Button());
			this->saveFileButton = (gcnew System::Windows::Forms::Button());
			this->listBoxEdges = (gcnew System::Windows::Forms::ListBox());
			this->addEdgeButton = (gcnew System::Windows::Forms::Button());
			this->textBoxEdgeY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEdgeX = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->listBoxPoints = (gcnew System::Windows::Forms::ListBox());
			this->addPointButton = (gcnew System::Windows::Forms::Button());
			this->textBoxPointY = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPointX = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileLocationButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GrahamChart))->BeginInit();
			this->tabControlStats->SuspendLayout();
			this->tabPageStats->SuspendLayout();
			this->tabPageNewFile->SuspendLayout();
			this->SuspendLayout();
			// 
			// GrahamChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->GrahamChart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->GrahamChart->Legends->Add(legend1);
			this->GrahamChart->Location = System::Drawing::Point(13, 13);
			this->GrahamChart->Name = L"GrahamChart";
			series1->BorderWidth = 2;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::FastPoint;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle;
			series1->Name = L"Series1";
			this->GrahamChart->Series->Add(series1);
			this->GrahamChart->Size = System::Drawing::Size(879, 639);
			this->GrahamChart->TabIndex = 0;
			this->GrahamChart->Text = L"chart1";
			// 
			// chooseFileButton
			// 
			this->chooseFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->chooseFileButton->Location = System::Drawing::Point(898, 12);
			this->chooseFileButton->Name = L"chooseFileButton";
			this->chooseFileButton->Size = System::Drawing::Size(327, 55);
			this->chooseFileButton->TabIndex = 2;
			this->chooseFileButton->Text = L"Wybierz plik z punktami";
			this->chooseFileButton->UseVisualStyleBackColor = true;
			this->chooseFileButton->Click += gcnew System::EventHandler(this, &MainWindow::button2_Click);
			// 
			// grahamButton
			// 
			this->grahamButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->grahamButton->Location = System::Drawing::Point(898, 74);
			this->grahamButton->Name = L"grahamButton";
			this->grahamButton->Size = System::Drawing::Size(327, 55);
			this->grahamButton->TabIndex = 3;
			this->grahamButton->Text = L"Wykonaj algorytm Grahama";
			this->grahamButton->UseVisualStyleBackColor = true;
			this->grahamButton->Click += gcnew System::EventHandler(this, &MainWindow::grahamButton_Click);
			// 
			// kruskalButton
			// 
			this->kruskalButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->kruskalButton->Location = System::Drawing::Point(898, 136);
			this->kruskalButton->Name = L"kruskalButton";
			this->kruskalButton->Size = System::Drawing::Size(327, 55);
			this->kruskalButton->TabIndex = 4;
			this->kruskalButton->Text = L"Wykonaj algorytm Kruskala";
			this->kruskalButton->UseVisualStyleBackColor = true;
			this->kruskalButton->Click += gcnew System::EventHandler(this, &MainWindow::kruskalButton_Click);
			// 
			// tabControlStats
			// 
			this->tabControlStats->Controls->Add(this->tabPageStats);
			this->tabControlStats->Controls->Add(this->tabPageNewFile);
			this->tabControlStats->Location = System::Drawing::Point(898, 197);
			this->tabControlStats->Name = L"tabControlStats";
			this->tabControlStats->SelectedIndex = 0;
			this->tabControlStats->Size = System::Drawing::Size(327, 467);
			this->tabControlStats->TabIndex = 5;
			// 
			// tabPageStats
			// 
			this->tabPageStats->Controls->Add(this->statLabel4);
			this->tabPageStats->Controls->Add(this->statListBox);
			this->tabPageStats->Controls->Add(this->statLabel3);
			this->tabPageStats->Controls->Add(this->statLabel2);
			this->tabPageStats->Controls->Add(this->statLabel1);
			this->tabPageStats->Location = System::Drawing::Point(4, 22);
			this->tabPageStats->Name = L"tabPageStats";
			this->tabPageStats->Padding = System::Windows::Forms::Padding(3);
			this->tabPageStats->Size = System::Drawing::Size(319, 441);
			this->tabPageStats->TabIndex = 0;
			this->tabPageStats->Text = L"Statystyki";
			this->tabPageStats->UseVisualStyleBackColor = true;
			// 
			// statLabel4
			// 
			this->statLabel4->Location = System::Drawing::Point(3, 72);
			this->statLabel4->Name = L"statLabel4";
			this->statLabel4->Size = System::Drawing::Size(313, 42);
			this->statLabel4->TabIndex = 4;
			this->statLabel4->Text = L"label3";
			this->statLabel4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->statLabel4->Visible = false;
			// 
			// statListBox
			// 
			this->statListBox->FormattingEnabled = true;
			this->statListBox->Location = System::Drawing::Point(3, 117);
			this->statListBox->Name = L"statListBox";
			this->statListBox->Size = System::Drawing::Size(313, 316);
			this->statListBox->TabIndex = 3;
			this->statListBox->Visible = false;
			// 
			// statLabel3
			// 
			this->statLabel3->Location = System::Drawing::Point(3, 49);
			this->statLabel3->Name = L"statLabel3";
			this->statLabel3->Size = System::Drawing::Size(313, 23);
			this->statLabel3->TabIndex = 2;
			this->statLabel3->Text = L"label3";
			this->statLabel3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->statLabel3->Visible = false;
			// 
			// statLabel2
			// 
			this->statLabel2->Location = System::Drawing::Point(3, 26);
			this->statLabel2->Name = L"statLabel2";
			this->statLabel2->Size = System::Drawing::Size(313, 23);
			this->statLabel2->TabIndex = 1;
			this->statLabel2->Text = L"label2";
			this->statLabel2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->statLabel2->Visible = false;
			// 
			// statLabel1
			// 
			this->statLabel1->Location = System::Drawing::Point(3, 3);
			this->statLabel1->Name = L"statLabel1";
			this->statLabel1->Size = System::Drawing::Size(313, 23);
			this->statLabel1->TabIndex = 0;
			this->statLabel1->Text = L"label1";
			this->statLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->statLabel1->Visible = false;
			// 
			// tabPageNewFile
			// 
			this->tabPageNewFile->Controls->Add(this->deleteEdgeButton);
			this->tabPageNewFile->Controls->Add(this->deletePointButton);
			this->tabPageNewFile->Controls->Add(this->saveFileButton);
			this->tabPageNewFile->Controls->Add(this->listBoxEdges);
			this->tabPageNewFile->Controls->Add(this->addEdgeButton);
			this->tabPageNewFile->Controls->Add(this->textBoxEdgeY);
			this->tabPageNewFile->Controls->Add(this->textBoxEdgeX);
			this->tabPageNewFile->Controls->Add(this->label4);
			this->tabPageNewFile->Controls->Add(this->label5);
			this->tabPageNewFile->Controls->Add(this->label6);
			this->tabPageNewFile->Controls->Add(this->listBoxPoints);
			this->tabPageNewFile->Controls->Add(this->addPointButton);
			this->tabPageNewFile->Controls->Add(this->textBoxPointY);
			this->tabPageNewFile->Controls->Add(this->textBoxPointX);
			this->tabPageNewFile->Controls->Add(this->label3);
			this->tabPageNewFile->Controls->Add(this->label2);
			this->tabPageNewFile->Controls->Add(this->label1);
			this->tabPageNewFile->Controls->Add(this->saveFileLocationButton);
			this->tabPageNewFile->Location = System::Drawing::Point(4, 22);
			this->tabPageNewFile->Name = L"tabPageNewFile";
			this->tabPageNewFile->Padding = System::Windows::Forms::Padding(3);
			this->tabPageNewFile->Size = System::Drawing::Size(319, 441);
			this->tabPageNewFile->TabIndex = 1;
			this->tabPageNewFile->Text = L"Utwórz nowy plik";
			this->tabPageNewFile->UseVisualStyleBackColor = true;
			// 
			// deleteEdgeButton
			// 
			this->deleteEdgeButton->Location = System::Drawing::Point(162, 301);
			this->deleteEdgeButton->Name = L"deleteEdgeButton";
			this->deleteEdgeButton->Size = System::Drawing::Size(150, 23);
			this->deleteEdgeButton->TabIndex = 17;
			this->deleteEdgeButton->Text = L"Usuñ krawêdŸ";
			this->deleteEdgeButton->UseVisualStyleBackColor = true;
			this->deleteEdgeButton->Click += gcnew System::EventHandler(this, &MainWindow::deleteEdgeButton_Click);
			// 
			// deletePointButton
			// 
			this->deletePointButton->Location = System::Drawing::Point(162, 107);
			this->deletePointButton->Name = L"deletePointButton";
			this->deletePointButton->Size = System::Drawing::Size(150, 23);
			this->deletePointButton->TabIndex = 16;
			this->deletePointButton->Text = L"Usuñ punkt";
			this->deletePointButton->UseVisualStyleBackColor = true;
			this->deletePointButton->Click += gcnew System::EventHandler(this, &MainWindow::deletePointButton_Click);
			// 
			// saveFileButton
			// 
			this->saveFileButton->Location = System::Drawing::Point(6, 415);
			this->saveFileButton->Name = L"saveFileButton";
			this->saveFileButton->Size = System::Drawing::Size(306, 23);
			this->saveFileButton->TabIndex = 15;
			this->saveFileButton->Text = L"Zapisz plik";
			this->saveFileButton->UseVisualStyleBackColor = true;
			this->saveFileButton->Click += gcnew System::EventHandler(this, &MainWindow::saveFileButton_Click);
			// 
			// listBoxEdges
			// 
			this->listBoxEdges->FormattingEnabled = true;
			this->listBoxEdges->Location = System::Drawing::Point(6, 330);
			this->listBoxEdges->Name = L"listBoxEdges";
			this->listBoxEdges->Size = System::Drawing::Size(306, 82);
			this->listBoxEdges->TabIndex = 14;
			// 
			// addEdgeButton
			// 
			this->addEdgeButton->Location = System::Drawing::Point(6, 301);
			this->addEdgeButton->Name = L"addEdgeButton";
			this->addEdgeButton->Size = System::Drawing::Size(150, 23);
			this->addEdgeButton->TabIndex = 13;
			this->addEdgeButton->Text = L"Dodaj krawêdŸ";
			this->addEdgeButton->UseVisualStyleBackColor = true;
			this->addEdgeButton->Click += gcnew System::EventHandler(this, &MainWindow::addEdgeButton_Click);
			// 
			// textBoxEdgeY
			// 
			this->textBoxEdgeY->Location = System::Drawing::Point(162, 275);
			this->textBoxEdgeY->Name = L"textBoxEdgeY";
			this->textBoxEdgeY->Size = System::Drawing::Size(150, 20);
			this->textBoxEdgeY->TabIndex = 12;
			// 
			// textBoxEdgeX
			// 
			this->textBoxEdgeX->Location = System::Drawing::Point(6, 275);
			this->textBoxEdgeX->Name = L"textBoxEdgeX";
			this->textBoxEdgeX->Size = System::Drawing::Size(150, 20);
			this->textBoxEdgeX->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(3, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(313, 23);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Krawêdzie";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(163, 249);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(150, 23);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Index punktu 2";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(3, 249);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(150, 23);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Index punktu 1";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listBoxPoints
			// 
			this->listBoxPoints->FormattingEnabled = true;
			this->listBoxPoints->Location = System::Drawing::Point(6, 136);
			this->listBoxPoints->Name = L"listBoxPoints";
			this->listBoxPoints->Size = System::Drawing::Size(306, 82);
			this->listBoxPoints->TabIndex = 7;
			// 
			// addPointButton
			// 
			this->addPointButton->Location = System::Drawing::Point(6, 107);
			this->addPointButton->Name = L"addPointButton";
			this->addPointButton->Size = System::Drawing::Size(150, 23);
			this->addPointButton->TabIndex = 6;
			this->addPointButton->Text = L"Dodaj punkt";
			this->addPointButton->UseVisualStyleBackColor = true;
			this->addPointButton->Click += gcnew System::EventHandler(this, &MainWindow::addPointButton_Click);
			// 
			// textBoxPointY
			// 
			this->textBoxPointY->Location = System::Drawing::Point(162, 81);
			this->textBoxPointY->Name = L"textBoxPointY";
			this->textBoxPointY->Size = System::Drawing::Size(150, 20);
			this->textBoxPointY->TabIndex = 5;
			// 
			// textBoxPointX
			// 
			this->textBoxPointX->Location = System::Drawing::Point(6, 81);
			this->textBoxPointX->Name = L"textBoxPointX";
			this->textBoxPointX->Size = System::Drawing::Size(150, 20);
			this->textBoxPointX->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(3, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(313, 23);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Punkty";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(163, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Wspó³rzêdne Y";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(3, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Wspó³rzêdne X";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// saveFileLocationButton
			// 
			this->saveFileLocationButton->Location = System::Drawing::Point(6, 6);
			this->saveFileLocationButton->Name = L"saveFileLocationButton";
			this->saveFileLocationButton->Size = System::Drawing::Size(307, 23);
			this->saveFileLocationButton->TabIndex = 0;
			this->saveFileLocationButton->Text = L"Wybierz lokalizacjê zapisu";
			this->saveFileLocationButton->UseVisualStyleBackColor = true;
			this->saveFileLocationButton->Click += gcnew System::EventHandler(this, &MainWindow::saveFileLocationButton_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1232, 665);
			this->Controls->Add(this->tabControlStats);
			this->Controls->Add(this->kruskalButton);
			this->Controls->Add(this->grahamButton);
			this->Controls->Add(this->chooseFileButton);
			this->Controls->Add(this->GrahamChart);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainWindow";
			this->ShowIcon = false;
			this->Text = L"Wizualizacja algorytmu Kruskala i Grahama";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GrahamChart))->EndInit();
			this->tabControlStats->ResumeLayout(false);
			this->tabPageStats->ResumeLayout(false);
			this->tabPageNewFile->ResumeLayout(false);
			this->tabPageNewFile->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	auto fileDialog = (gcnew OpenFileDialog());
	msclr::interop::marshal_context context;

	System::Windows::Forms::DialogResult result = fileDialog->ShowDialog();

	if (result == System::Windows::Forms::DialogResult::OK)
	{
		filePath = context.marshal_as<std::string>(fileDialog->FileName);
	}
}
private: System::Void grahamButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//sprawdzanie czy zostala podana sciezka do pliku
	if (filePath.empty())
	{
		grahamButton->Text = L"Najpierw wybierz plik!";
	}
	else
	{
		grahamButton->Text = L"Wykonaj algorytm Grahama";

		//czyszczenie poprzednich wykresow
		GrahamChart->Series->Clear();

		//czytanie punktow z pliku
		auto pointsArray = algo::ReadPointsFromFile(filePath);

		//rysowanie punktow na wykresie
		Series^ seriesPoints = (gcnew Series());
		seriesPoints->Name = L"Punkty";
		this->GrahamChart->Series->Add(seriesPoints);

		seriesPoints->ChartType = SeriesChartType::FastPoint;
		seriesPoints->MarkerStyle = MarkerStyle::Circle;

		for (int i = 0; i < pointsArray->length; i++)
		{
			seriesPoints->Points->AddXY(pointsArray->array[i].x, pointsArray->array[i].y);
		}

		//wykonanie algorytmu Grahama
		algo::timeStruct* ts = new algo::timeStruct();
		algo::LL<algo::Point> *result = Graham(pointsArray, ts);

		//rysowanie convex hull na wykresie
		Series^ seriesConvexHull = (gcnew Series());
		seriesConvexHull->Name = L"Convex hull";
		this->GrahamChart->Series->Add(seriesConvexHull);

		seriesConvexHull->ChartType = SeriesChartType::FastLine;
		seriesConvexHull->Color = Color::Red;

		auto tmp = result->GetHead();
		for (int i = 0; i < result->GetSize(); i++)
		{
			seriesConvexHull->Points->AddXY(tmp->data.x, tmp->data.y);
			tmp = tmp->next;
		}
		tmp = result->GetHead();
		seriesConvexHull->Points->AddXY(tmp->data.x, tmp->data.y);

		//dodawanie statystyk
		statListBox->Visible = true;
		statLabel1->Visible = true;
		statLabel1->Text = gcnew String("Czas sortowania wyniós³: " + ts->sortTime + "ms");
		statLabel2->Visible = true;
		statLabel2->Text = gcnew String("Czas wykonania g³ównej pêtli wyniós³: " + ts->mainTime + "ms");
		statLabel3->Visible = true;
		statLabel3->Text = gcnew String("£¹czny czas wykonania algorytmu wyniós³: " + ts->fullTime + "ms");
		statLabel4->Visible = true;
		statLabel4->Text = gcnew String("Lista punktów znajduj¹cych siê w Convex Hull ([index] x,y)");

		statListBox->Items->Clear();
		for (int i = 0; i < result->GetSize(); i++)
		{
			statListBox->Items->Add(gcnew String("[" + tmp->data.index + "] " + tmp->data.x + ", " + tmp->data.y));
			tmp = tmp->next;
		}

		//czyszczenie pamieci
		delete ts;
		delete result;
	}

}
private: System::Void kruskalButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//sprawdzanie czy zostala podana sciezka do pliku
	if (filePath.empty())
	{
		kruskalButton->Text = L"Najpierw wybierz plik!";
	}
	else
	{
		//czyszczenie poprzednich wykresow
		GrahamChart->Series->Clear();
		kruskalButton->Text = L"Wykonaj algorytm Kruskala";

		//czytanie punktow z pliku
		algo::Graph* graph = algo::ReadGraphFromFile(filePath);

		//rysowanie punktow na wykresie
		Series^ seriesPoints = (gcnew Series());
		seriesPoints->Name = L"Punkty";
		this->GrahamChart->Series->Add(seriesPoints);

		seriesPoints->ChartType = SeriesChartType::FastPoint;
		seriesPoints->MarkerStyle = MarkerStyle::Circle;
		seriesPoints->Color = Color::Black;

		for (int i = 0; i < graph->graphNodeAmount; i++)
		{
			seriesPoints->Points->AddXY(graph->graphNodeArray[i].x, graph->graphNodeArray[i].y);
		}

		//rysowanie krawedzi na wykresie
		Series^ seriesEdges;
		for (int i = 0; i < graph->graphEdgeAmount; i++)
		{
			seriesEdges = (gcnew Series());
			this->GrahamChart->Series->Add(seriesEdges);

			seriesEdges->ChartType = SeriesChartType::FastLine;
			seriesEdges->Color = Color::Aqua;
			if (i > 0)seriesEdges->IsVisibleInLegend = false;
			else seriesEdges->Name = L"Krawêdzie";

			seriesEdges->Points->AddXY(graph->graphNodeArray[graph->graphEdgeArray[i].node1].x, graph->graphNodeArray[graph->graphEdgeArray[i].node1].y);
			seriesEdges->Points->AddXY(graph->graphNodeArray[graph->graphEdgeArray[i].node2].x, graph->graphNodeArray[graph->graphEdgeArray[i].node2].y);
		}

		//wykonanie algorytmu kruskala
		algo::timeStruct* ts = new algo::timeStruct();
		algo::LL<algo::GraphEdge>* MST = algo::Kruskal(graph, ts);

		//rysowanie MST na wykresie
		for (int i = 0; i < MST->GetSize(); i++)
		{
			seriesEdges = (gcnew Series());
			this->GrahamChart->Series->Add(seriesEdges);

			seriesEdges->ChartType = SeriesChartType::FastLine;
			seriesEdges->Color = Color::Red;
			if (i > 0)seriesEdges->IsVisibleInLegend = false;
			else seriesEdges->Name = L"MST";

			algo::GraphEdge tmp = MST->Get(i);

			seriesEdges->Points->AddXY(graph->graphNodeArray[tmp.node1].x, graph->graphNodeArray[tmp.node1].y);
			seriesEdges->Points->AddXY(graph->graphNodeArray[tmp.node2].x, graph->graphNodeArray[tmp.node2].y);
		}

		//dodawanie statystyk
		statListBox->Visible = true;
		statLabel1->Visible = true;
		statLabel1->Text = gcnew String("Czas sortowania wyniós³: " + ts->sortTime + "ms");
		statLabel2->Visible = true;
		statLabel2->Text = gcnew String("Czas wykonania g³ównej pêtli wyniós³: " + ts->mainTime + "ms");
		statLabel3->Visible = true;
		statLabel3->Text = gcnew String("£¹czny czas wykonania algorytmu wyniós³: " + ts->fullTime + "ms");
		statLabel4->Visible = true;
		statLabel4->Text = gcnew String("Lista krawêdzi znajduj¹cych siê w MST ([index]x,y | [index]x,y | dlugosc)");

		auto tmp = MST->GetHead();
		statListBox->Items->Clear();
		for (int i = 0; i < MST->GetSize(); i++)
		{
			int index1 = tmp->data.node1;
			int index2 = tmp->data.node2;
			statListBox->Items->Add(gcnew String("[" + index1 + "]"+graph->graphNodeArray[index1].x +" , "+ graph->graphNodeArray[index1].y + " | " + "[" + index2 + "]" + graph->graphNodeArray[index2].x + " , " + graph->graphNodeArray[index2].y + " | " + tmp->data.cost));
			tmp = tmp->next;
		}

		//czyszczenie pamiêci
		delete ts;
		delete MST;
	}
}
private: System::Void saveFileLocationButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	auto folderDialog = (gcnew FolderBrowserDialog());
	msclr::interop::marshal_context context;

	System::Windows::Forms::DialogResult result = folderDialog->ShowDialog();

	if (result == System::Windows::Forms::DialogResult::OK)
	{
		saveFilePath = context.marshal_as<std::string>(folderDialog->SelectedPath);
	}
}
private: System::Void addPointButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	listBoxPoints->Items->Add(gcnew String(textBoxPointX->Text + " " + textBoxPointY->Text));
	textBoxPointX->Clear();
	textBoxPointY->Clear();
}
private: System::Void addEdgeButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	msclr::interop::marshal_context context;

	int index1 = std::stoi(context.marshal_as<std::string>(textBoxEdgeX->Text));
	int index2 = std::stoi(context.marshal_as<std::string>(textBoxEdgeY->Text));
	std::string point1string = context.marshal_as<std::string>(listBoxPoints->Items[index1]->ToString());
	std::string point2string = context.marshal_as<std::string>(listBoxPoints->Items[index2]->ToString());
	vector<float> point1xy;
	vector<float> point2xy;

	std::string space_delimiter = " ";

	size_t pos = 0;
	pos = point1string.find(space_delimiter);
	point1xy.push_back(std::stof(point1string.substr(0, pos)));
	point1string.erase(0, pos + space_delimiter.length());
	point1xy.push_back(std::stof(point1string.substr(0, pos)));

	pos = point2string.find(space_delimiter);
	point2xy.push_back(std::stof(point2string.substr(0, pos)));
	point2string.erase(0, pos + space_delimiter.length());
	point2xy.push_back(std::stof(point2string.substr(0, pos)));

	float cost = Math::Sqrt(Math::Pow((point1xy[0] - point2xy[0]), 2) + Math::Pow((point1xy[1] - point2xy[1]), 2));

	listBoxEdges->Items->Add(gcnew String(index1 + " " + index2 + " " + cost));
	textBoxEdgeX->Clear();
	textBoxEdgeY->Clear();
}
private: System::Void saveFileButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (saveFilePath.empty())
	{
		saveFileButton->Text = L"Najpierw wybierz lokalizacjê zapisu!";
	}
	else
	{
		std::string fullFileName = saveFilePath + "plik.txt";
		msclr::interop::marshal_context context;

		std::ofstream writer(fullFileName);
		if (writer.is_open())
		{
			writer << listBoxPoints->Items->Count << "\n";
			for (int i = 0; i < listBoxPoints->Items->Count; i++)
			{
				writer << context.marshal_as<std::string>(listBoxPoints->Items[i]->ToString()) << "\n";
			}
			writer << listBoxEdges->Items->Count << "\n";
			for (int i = 0; i < listBoxEdges->Items->Count; i++)
			{
				writer << context.marshal_as<std::string>(listBoxEdges->Items[i]->ToString()) << "\n";
			}
		}

		writer.close();
	}
}
private: System::Void deletePointButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	listBoxPoints->Items->RemoveAt(listBoxPoints->SelectedIndex);
}
private: System::Void deleteEdgeButton_Click(System::Object^ sender, System::EventArgs^ e) 
{
	listBoxEdges->Items->RemoveAt(listBoxEdges->SelectedIndex);
}
};
}
