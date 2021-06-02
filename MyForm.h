#pragma once

#include "Dyhotomia.h"

namespace L3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			dyh->setVolumes(2, 3);
			dyh->setTolerance(0.01);
			Bitmap^ image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);

			for (int x = 0; x < image->Width; x++)
			{
				for (int y = 0; y < image->Height; y++)
				{
					if (y == image->Height / 2)
					{
						image->SetPixel(x, y, Color::FromArgb(0, 0, 0));
					}
					else
					{
						image->SetPixel(x, y, Color::FromArgb(255, 255, 255));
					}
				}
			}

			double root = dyh->Solve();

			//double yStep = (dyh->funcMax() - dyh->funcMax()) / image->Height;
			double xStep = (dyh->getB() - dyh->getA()) / image->Width;
			xStep *= xStep < 0 ? -1 : 1;
			for (int x; x < image->Width; x++)
			{
				double y = dyh->func(dyh->getA() + xStep * x);
				y = 1+(y - dyh->funcMin()) / ((dyh->funcMin() - dyh->funcMax()));
				if (y < 0)
				{
					y = 0;
				}
				if (y > 1)
				{
					y = 1;
				}
				if (Math::Abs(root - (dyh->getA() + xStep * x)) <= 0.004)
				{
					image->SetPixel(x, Math::Floor((y * (image->Height - 1)))-2, Color::FromArgb(200, 3, 20));
					image->SetPixel(x, Math::Floor((y * (image->Height - 1)))-1, Color::FromArgb(200, 3, 20));
					image->SetPixel(x, Math::Floor((y * (image->Height - 1))), Color::FromArgb(200, 3, 20));
					image->SetPixel(x, Math::Floor((y * (image->Height - 1)))+1, Color::FromArgb(200, 3, 20));
					image->SetPixel(x, Math::Floor((y * (image->Height - 1)))+2, Color::FromArgb(200, 3, 20));
				}
				else
				{
					image->SetPixel(x, Math::Floor((y * (image->Height - 1))), Color::FromArgb(20, 3, 200));
				}
			}

			pictureBox1->Image = image;
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   Dyhotomia^ dyh = gcnew Dyhotomia();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(260, 237);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
