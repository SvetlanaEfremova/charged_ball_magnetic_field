#pragma once


#include <cmath>

namespace курсовая {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;





	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
double R;
double q;
double w;
double X0;
double Y0;
double Y02;
double V;
double V1;
double V2;
double h1;
double h2;
double h3;
bool Число1;
bool Число2;
bool Число3;
bool Число4;
bool Число5;
bool Число6;
double X;
double Y;
double Z;
bool График1;
bool График2;
bool График3;
bool ВводX;
bool ВводY;
bool ВводZ;
Bitmap^ MyBmp1;
Bitmap^ MyBmp2;
Bitmap^ MyBmp3;
Graphics^ gr1;
Graphics^ gr2;
Graphics^ gr3;
Pen^ bluePen;
Pen^ orangePen;
Pen^ greenPen;
Pen^ blackPen;
Brush^ blackBrush;
	private: System::Windows::Forms::Label^  label4;
	public: 
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Button^  button9;



  double PmСферы(double R, double q, double w)
{
	
  double s=0;
  double dh=0.1;
  for (double h=0; h<3.14; h+=dh)
  {
    s+=0.5*(pow(sin(h),3)+pow(sin(h+dh),3))*dh;
  }
  double m=0.25*pow(R,2)*q*w*s;
  return m;
};
double PmШара(double R, double q, double w)
{
	double Qобъём=q/((4/3)*3.14*pow(R,3));
	double m=0;
	double dr=0.001;
	double c=q*w/pow(R,3);
	for (double r=0;r<=R;r+=dr)
	{
    	m+=0.5*dr*(pow(r,4)+pow(r+dr,4));
	}
	return c*m;
}

 double Bz(double R, double q,double w,double x,double y, double z)
 {
double r=pow(pow(x,2)+pow(y,2)+pow(z,2),0.5);
if (checkBox1->Checked==true)
   
   return pow(10.,-7)*(3*PmШара(R,q,w)*z*z/pow(r,5)-PmШара(R,q,w)/pow(r,3));
else
return pow(10.,-7)*(3*PmСферы(R,q,w)*z*z/pow(r,5)-PmСферы(R,q,w)/pow(r,3));
 }

double Bx(double R, double q,double w,double x,double y, double z)
 {
double r=pow(pow(x,2)+pow(y,2)+pow(z,2),0.5);
if (checkBox1->Checked==true)
  return pow(10.,-7)*3*PmШара(R,q,w)*z*x/pow(r,5);
else
return pow(10.,-7)*3*PmСферы(R,q,w)*z*x/pow(r,5);
 }
double By(double R, double q,double w,double x,double y, double z)
 {
double r=pow(pow(x,2)+pow(y,2)+pow(z,2),0.5);
if (checkBox1->Checked==true)
  return pow(10.,-7)*3*PmШара(R,q,w)*z*y/pow(r,5);
else
return pow(10.,-7)*3*PmСферы(R,q,w)*z*y/pow(r,5);
 }
double R1;
void НарисоватьГрафик1()
{
MyBmp1=gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
Font=gcnew System::Drawing::Font(label1->Font->Name,label1->Font->Size, label1->Font->Style);
gr1 = Graphics::FromImage(MyBmp1);
gr1->DrawLine(blackPen,0,int(Y0),int(pictureBox1->Width),int(Y0));
gr1->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y0)-3,int(pictureBox1->Width),int(Y0));
gr1->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y0)+3,int(pictureBox1->Width),int(Y0));
gr1->DrawString("0X",Font,blackBrush,pictureBox1->Width-25,Y0+10);
gr1->DrawLine(blackPen,int(X0),0,int(X0),int(pictureBox1->Height));
gr1->DrawLine(blackPen,int(X0)-3,8,int(X0),0);
gr1->DrawLine(blackPen,int(X0),0,int(X0)+3,8);
gr1->DrawString("Bx(x)",Font,blackBrush,int(X0)-35,20);
h1=R/5;
	for(double x=-10*R;x<10*R;x+=h1)
		 for(double y=-10*R;y<10*R;y+=10*h1) 
			 for(double z=-10*R;z<10*R;z+=10*h1)
	 if (((x<-R)||(x>R))&&(X0+V*x)>0&&((X0+V*x)<pictureBox1->Width)&&(Y0-Bx(R,q,w,x,y,z)/V1<pictureBox1->Height)&&(Y0-Bx(R,q,w,x,y,z)/V1>0))
gr1->DrawRectangle(blackPen,X0+V*x,Y0-Bx(R,q,w,x,y,z)/V1,1,1);
gr1->DrawEllipse(greenPen, int(X0-V*R),int(Y0-V*R),int(2*V*R),int(2*V*R));
pictureBox1->Image=MyBmp1;
}
void НарисоватьГрафик2()
{
MyBmp2 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
gr2 = Graphics::FromImage(MyBmp2);
greenPen=gcnew Pen(Color::Green);
gr2->DrawEllipse(greenPen, int(X0-V*R),int(Y02-V*R),int(2*V*R),int(2*V*R));
blackPen=gcnew Pen(Color::Black);
orangePen=gcnew Pen(Color::OrangeRed);
Brush ^ blackBrush = gcnew SolidBrush(Color::Black);
Font=gcnew System::Drawing::Font(label1->Font->Name,label1->Font->Size, label1->Font->Style);
gr2->DrawLine(blackPen,0,int(Y02),int(pictureBox1->Width),int(Y02));
gr2->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y02)-3,int(pictureBox1->Width),int(Y02));
gr2->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y02)+3,int(pictureBox1->Width),int(Y02));
gr2->DrawString("0Z",Font,blackBrush,pictureBox1->Width-25,Y02+10);
gr2->DrawLine(blackPen,int(X0),0,int(X0),int(pictureBox1->Height));
gr2->DrawLine(blackPen,int(X0)-3,8,int(X0),0);
gr2->DrawLine(blackPen,int(X0),0,int(X0)+3,8);
gr2->DrawString("Bz(z)",Font,blackBrush,int(X0)-35,20);
h2=R/4;
for(double x=-5*R;x<5*R;x+=h2)
		 for(double y=-5*R;y<5*R;y+=h2) 
			 for(double z=-5*R;z<5*R;z+=h2)
	 if (((z<-R)||(z>R))&&((X0+V*z)>0)&&((X0+V*z)<pictureBox1->Width)&&(Y02-Bz(R,q,w,x,y,z)/V2<pictureBox1->Height)&&(Y02-Bz(R,q,w,x,y,z)/V2>0))
 gr2->DrawRectangle(orangePen,X0+V*z,Y02-Bz(R,q,w,x,y,z)/V2,1,1);
pictureBox1->Image=MyBmp2;
}
void НарисоватьГрафик3()
{
MyBmp3=gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
Font=gcnew System::Drawing::Font(label1->Font->Name,label1->Font->Size, label1->Font->Style);
gr3 = Graphics::FromImage(MyBmp3);
gr3->DrawLine(blackPen,0,int(Y0),int(pictureBox1->Width),int(Y0));
gr3->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y0)-3,int(pictureBox1->Width),int(Y0));
gr3->DrawLine(blackPen,int(pictureBox1->Width)-8,int(Y0)+3,int(pictureBox1->Width),int(Y0));
gr3->DrawString("Bx",Font,blackBrush,pictureBox1->Width-25,Y0+10);
gr3->DrawLine(blackPen,int(X0),0,int(X0),int(pictureBox1->Height));
gr3->DrawLine(blackPen,int(X0)-3,8,int(X0),0);
gr3->DrawLine(blackPen,int(X0),0,int(X0)+3,8);
gr3->DrawString("Bz(Bx)",Font,blackBrush,int(X0)-35,20);
h3=R/5;
	for(double x=-5*R;x<5*R;x+=h3)
		 for(double y=-5*R;y<5*R;y+=h3) 
			 for(double z=-5*R;z<5*R;z+=h3)
	 if (((x<-R)||(x>R))&&((y<-R)||(y>R))&&((z<-R)||(z>R))&&((X0+Bx(R,q,w,x,y,z)/V1)>0)&&((X0+Bx(R,q,w,x,y,z)/V1)<pictureBox1->Width)&&((Y0-Bz(R,q,w,x,y,z)/V2)<pictureBox1->Height)&&(Y0-Bz(R,q,w,x,y,z)/V2>0))
gr3->DrawRectangle(bluePen,X0+Bx(R,q,w,x,y,z)/V1,Y0-Bz(R,q,w,x,y,z)/V2,1,1);
pictureBox1->Image=MyBmp3;
}
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	public: 

	public: 
		
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;
	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Заряд шара:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 36);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(43, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(97, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(40, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Радиус шара:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 105);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Угл. скорость вращения:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(148, 102);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(42, 20);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(27, 294);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 29);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Построить график Bx (x)";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(675, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 25);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Закрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(257, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(536, 438);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(27, 329);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(163, 30);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Построить график Bz (z)";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(27, 365);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(163, 30);
			this->button5->TabIndex = 12;
			this->button5->Text = L"Построить график Bz (Bx)";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(24, 143);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(182, 17);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Заряд распределён по объёму";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 433);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Масштаб";
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(533, 453);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(121, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Сохранить в файл";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(88, 429);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(36, 21);
			this->button7->TabIndex = 16;
			this->button7->Text = L"-";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(130, 429);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(36, 20);
			this->button8->TabIndex = 17;
			this->button8->Text = L"+";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(151, 39);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 13);
			this->label5->TabIndex = 18;
			this->label5->Text = L"м";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(143, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(20, 13);
			this->label6->TabIndex = 19;
			this->label6->Text = L"Кл";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(196, 106);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(36, 13);
			this->label7->TabIndex = 20;
			this->label7->Text = L"рад/с";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(12, 214);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(232, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Значение магнитной индукции поля в точке:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(12, 239);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(17, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"X:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(31, 235);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(31, 20);
			this->textBox4->TabIndex = 23;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &Form1::textBox4_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(77, 238);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(17, 13);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Y:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(97, 235);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(34, 20);
			this->textBox5->TabIndex = 25;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Form1::textBox5_TextChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(146, 238);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(17, 13);
			this->label11->TabIndex = 26;
			this->label11->Text = L"Z:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(162, 235);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(28, 20);
			this->textBox6->TabIndex = 27;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &Form1::textBox6_TextChanged);
			// 
			// button9
			// 
			this->button9->Enabled = false;
			this->button9->Location = System::Drawing::Point(30, 262);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(93, 26);
			this->button9->TabIndex = 28;
			this->button9->Text = L"Вывести";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(805, 482);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Ефремова С., гр.219";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
  
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
V1=abs(Bx(R,q,w,R+1,R+1,R+1))/Y0;
НарисоватьГрафик1();
График1=true;
График2=false;
График3=false;
button6->Enabled=true;
button7->Enabled=true;
button8->Enabled=true;
			 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
Application::Exit();
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
V2=abs(Bz(R,q,w,0,0,R))/Y02;
НарисоватьГрафик2();
График1=false;
График2=true;
График3=false;
button6->Enabled=true;
button7->Enabled=true;
button8->Enabled=true;
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
R1=pictureBox1->Width/10;
X0=0.5*pictureBox1->Width;
Y0=0.5*pictureBox1->Height;
Y02=Y0+2*R1;
MyBmp1 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
MyBmp2 = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
bluePen=gcnew Pen(Color::Blue);
orangePen=gcnew Pen(Color::Orange);
blackPen=gcnew Pen(Color::Black);
greenPen=gcnew Pen(Color::Green);
blackBrush = gcnew SolidBrush(Color::Black);
		 }

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число1=System::Double::TryParse(textBox1->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
R=t;
V=R1/R;
if (Число1 && Число2 && Число3)
 {
	 button1->Enabled=true;
     button3->Enabled=true;
     button5->Enabled=true;
 }
 else
{
	 button1->Enabled=false;
     button3->Enabled=false;
     button5->Enabled=false;
 }
if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
else
 button9->Enabled=false;
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число2=System::Double::TryParse(textBox2->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
q=t;
 if (Число1 && Число2 && Число3)
 {
	 button1->Enabled=true;
     button3->Enabled=true;
     button5->Enabled=true;
 }
 else
{
	 button1->Enabled=false;
     button3->Enabled=false;
     button5->Enabled=false;
 }
if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
else
 button9->Enabled=false;
		 }
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число3=System::Double::TryParse(textBox3->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
w=t;
 if (Число1 && Число2 && Число3)
 {
	 button1->Enabled=true;
     button3->Enabled=true;
	 button5->Enabled=true;
 }
else
{
	 button1->Enabled=false;
     button3->Enabled=false;
     button5->Enabled=false;
 }
if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
else
button9->Enabled=false;
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
V1=abs(Bx(R,q,w,R,0,R))/X0;
V2=0.08*abs(Bz(R,q,w,0,0,R))/Y0;
НарисоватьГрафик3();
График1=false;
График2=false;
График3=true;
button6->Enabled=true;
button7->Enabled=true;
button8->Enabled=true;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
V1=V1*2.5;
V2=V2*2.5;
V=V/2.5;
if (График1==true)
{
НарисоватьГрафик1();
}
else
if (График2==true)
{
НарисоватьГрафик2();
}
else
if (График3==true)
{
НарисоватьГрафик3();
}
		 }
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
V1=V1/2.5;
V2=V2/2.5;
V=V*2.5;
if (График1==true)
{
 НарисоватьГрафик1();
}
else
if (График2==true)
{
 НарисоватьГрафик2();
}
else
if (График3==true)
{
 НарисоватьГрафик3();
}
		 }
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
saveFileDialog1->DefaultExt = "*.bmp";
saveFileDialog1->Filter = "BMP files|*.bmp";
if (График1==true)
{if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0) 
{
 MyBmp1->Save(saveFileDialog1->FileName,System::Drawing::Imaging::ImageFormat::Bmp); 
}}
else
if (График2==true)
{if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0) 
{
 MyBmp2->Save(saveFileDialog1->FileName,System::Drawing::Imaging::ImageFormat::Bmp); 
}}
else
if (График3==true)
{if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0) 
{
 MyBmp3->Save(saveFileDialog1->FileName,System::Drawing::Imaging::ImageFormat::Bmp); 
}}
		 }
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {

if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
{String^ S="B="+System::Convert::ToString(pow(pow(Bx(R,q,w,X,Y,Z),2)+pow(By(R,q,w,X,Y,Z),2)+pow(Bz(R,q,w,X,Y,Z),2),0.5))+" Тл";
MessageBox::Show(S);}
		 }
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число4=System::Double::TryParse(textBox4->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
X=t;
 if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
 else
	 button9->Enabled=false;
		 }
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число5=System::Double::TryParse(textBox5->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
Y=t;
if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
 else
	 button9->Enabled=false;
		 }
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
double k;
double & t=k;
Число6=System::Double::TryParse(textBox6->Text,System::Globalization::NumberStyles::Number,System::Globalization::NumberFormatInfo::CurrentInfo, t);
Z=t;
 if (Число1&&Число2&&Число3&&Число4&&Число5&&Число6)
	 button9->Enabled=true;
 else
	 button9->Enabled=false;
		 }
};
}

