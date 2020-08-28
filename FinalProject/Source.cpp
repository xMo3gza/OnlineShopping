#include<iostream>
#include<string>
#include <fstream>
#include <windows.h>
#include<stdlib.h>
using namespace std;

string NameOfProd;
int c = 0;
int cart_cc;
const int max_num_of_prod = 10;
const int number_of_sellers = 100;
int ID = 0;
int IDOwner = 0;
int con1 = 0;
int cart_c = 0;
struct seller {
	string name;
	string adress;
	string gender;
	int age = 0;
	int IDOwner;
	string password;
	struct product {
		string product_name;
		float price;
		int quantity;
		int product_num;
	};
	struct shop {
		string name;
		string address;
		string category;
		product products[max_num_of_prod] = {};
		int num_of_products;
	};
	shop shop1;
};
seller s1[number_of_sellers];
struct cart {
	int product_num;
	string product_name;
	float product_price;
};
struct UserData {
	string Name;
	int ID;
	string password;
	int Age;
	string Gender;
	string Address;
	cart carts[max_num_of_prod];
	float total_bill;
};
UserData Users[100];
void LogoutUser();
void LogoutOwner();
void Cart()
{

	int ans = 1;
	while (ans == 1)
	{
		int entered_product_num;
		cout << "Enter the product number you want to add: ";
		while (!(cin >> entered_product_num)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter the product number: "; }
		for (int i = 0; i < s1[c - 1].shop1.num_of_products; i++)
		{
			if (entered_product_num == s1[c - 1].shop1.products[i].product_num)
			{
				Users[ID].carts[cart_c].product_name = s1[c - 1].shop1.products[i].product_name;
				Users[ID].carts[cart_c].product_price = s1[c - 1].shop1.products[i].price;
				s1[c - 1].shop1.products[i].quantity--;
				cart_c++;
			}
		}
		cout << "Do you wish to add another product ? [1] Yes \n \t\t\t\t     [2] No\n";
		cout << "-->  ";  cin >> ans;
	}
	cart_cc = cart_c;
}
void view_cart() {
	system("CLS");
	Users[ID].total_bill = 0;
	int cart_c = cart_cc;
	int ans = 1;
	cout << "----------\n" << "Your cart\n" << "----------\n";
	while (ans == 1) {
		for (int i = 0; i < cart_c; i++)
		{

			if (Users[ID].carts[i].product_price != NULL) {
				cout << "Product number < " << i + 1 << " >" << endl;
				cout << "Product name: " << Users[ID].carts[i].product_name << endl;
				cout << "Product price: " << Users[ID].carts[i].product_price << endl;
				Users[ID].total_bill += Users[ID].carts[i].product_price;
			}
		}
		cout << "Total bill: " << Users[ID].total_bill << endl;
		if (Users[ID].total_bill != 0) {
			cout << "Do you wish to delete any product ? [1] Yes \n \t\t\t\t    [2] No\n" << endl;

			int ProdNum;
			cout << "-- >  "; cin >> ans;
			if (ans == 1) {
				Users[ID].total_bill = 0;
				cout << "Enter Product number: "; cin >> ProdNum;
				ProdNum--;
				for (int i = 0; i < cart_c; i++) {
					if (i == ProdNum) {
						Users[ID].carts[i].product_price = NULL;
						s1[c - 1].shop1.products[i].quantity++;
					}
				}
			}

		}
		else {
			break;
		}
	}

}
void ProdOfShops() {
	for (int i = 0; i < number_of_sellers; i++) {

		if (c == i) {

			for (int i = 0; i < s1[c - 1].shop1.num_of_products; i++)
			{
				cout << " Product number: " << s1[c - 1].shop1.products[i].product_num << endl;
				cout << " Product name: " << s1[c - 1].shop1.products[i].product_name << endl;
				cout << " Product quantity: " << s1[c - 1].shop1.products[i].quantity << endl;
				cout << " Product price: " << s1[c - 1].shop1.products[i].price << endl;
			}
			Cart();
		}
	}
}
int Categories(int NumOfCat) {

	int ChoiceOfShop;
	switch (NumOfCat) {

	case 1:
		for (int i = 0; i < number_of_sellers; i++) {
			if (s1[i].shop1.category == "Clothes" || s1[i].shop1.category == "clothes") {
				cout << "[ " << i + 1 << " ] " << s1[i].shop1.name << endl;// << "   " << s1[i].shop1.address << endl;

			}
		}
		cout << "Which shop do you want ? (Enter shop number): ";
		while (!(cin >> ChoiceOfShop)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter shop number: "; }
		c = ChoiceOfShop;
		ProdOfShops();
		break;
	case 2:
		for (int i = 0; i < number_of_sellers; i++) {
			if (s1[i].shop1.category == "Electronics" || s1[i].shop1.category == "Electronics") {
				cout << "[ " << i + 1 << " ] " << s1[i].shop1.name << endl;// << "   " << s1[i].shop1.address << endl;

			}
		}
		cout << "Which shop do you want ? (Enter shop number): ";
		while (!(cin >> ChoiceOfShop)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter shop number: "; }
		c = ChoiceOfShop;
		ProdOfShops();
		break;

	case 3:
		for (int i = 0; i < number_of_sellers; i++) {
			if (s1[i].shop1.category == "Cars" || s1[i].shop1.category == "cars") {
				cout << "[ " << i + 1 << " ] " << s1[i].shop1.name << endl;// << "   " << s1[i].shop1.address << endl;

			}
		}
		cout << "Which shop do you want ? (Enter shop number): ";
		while (!(cin >> ChoiceOfShop)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter shop number: "; }
		c = ChoiceOfShop;
		ProdOfShops();
		break;

	case 4:
		for (int i = 0; i < number_of_sellers; i++) {
			if (s1[i].shop1.category == "Glasses" || s1[i].shop1.category == "glasses") {
				cout << "[ " << i + 1 << " ] " << s1[i].shop1.name << endl;// << "   " << s1[i].shop1.address << endl;

			}
		}
		cout << "Which shop do you want ? (Enter shop number): ";
		while (!(cin >> ChoiceOfShop)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter shop number: "; }
		c = ChoiceOfShop;
		ProdOfShops();
		break;

	default:
		cout << "Error !";
		break;
	}
	return NumOfCat, c;
}
void saveInfo() {
	ofstream ownerInfo("OwnerAccounts.txt");
	for (int i = 0; i < 100; i++) {
		if (!s1[i].password.empty()) {
			ownerInfo << s1[i].IDOwner + i << endl << s1[i].password << endl << s1[i].name << endl << s1[i].age << endl << s1[i].gender << endl << s1[i].adress << endl;
		}
	}
	ownerInfo.close();
	ofstream userInfo("UserAccounts.txt");
	for (int i = 0; i < 100; i++) {
		if (!Users[i].password.empty()) {
			userInfo << Users[i].ID + i << endl << Users[i].password << endl << Users[i].Name << endl << Users[i].Age << endl << Users[i].Gender << endl << Users[i].Address << endl;
		}
	}
	userInfo.close();
	ofstream productInfo("ProductData.txt");
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (!s1[i].shop1.products[j].product_name.empty()) {
				productInfo << s1[i].shop1.products[j].quantity << endl << s1[i].shop1.products[j].product_name << endl << s1[i].shop1.products[j].product_num << endl << s1[i].shop1.products[j].price << endl;
			}
		}
	}
	productInfo.close();
	ofstream shopInfo("ShopData.txt");
	for (int i = 0; i < 100; i++) {
		if (!s1[i].shop1.name.empty()) {
			shopInfo << s1[i].shop1.num_of_products << endl << s1[i].shop1.name << endl << s1[i].shop1.address << endl << s1[i].shop1.category << endl;
		}
	}
	shopInfo.close();
}
void EditOwner(int choice, int&IDOwner) {
	bool flag = true;
	char ans;
	string password;
	while (flag == true) {

		cout << "Do you wish to change something ? [Y / N]: "; cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			system("CLS");
			cout << "------------------\n" << "Edit your profile\n" << "------------------\n";
			cout << "Please select  [ 1)Name - 2)Password - 3)Age - 4)Gender - 5)Address- 6)shop name - 7) shop category - 8) shop address ]" << endl;
			cout << "-->  ";
			while (!(cin >> choice)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1-8]: "; }
			switch (choice) {
			case 1:
				cout << "Enter desired new name: ";
				cin.ignore();
				getline(cin, s1[IDOwner - 1].name);
				break;
			case 2:

				cout << "Please enter old password for verification: ";
				cin >> password;
				if (password == s1[IDOwner - 1].password) {
					cout << "Enter a new password: ";
					cin.ignore();
					getline(cin, s1[IDOwner - 1].password);
				}
				else {
					cout << "Incorrect password." << endl;
				}
				break;
			case 3:
				cout << "Enter a new age: ";
				while (!(cin >> s1[IDOwner - 1].age)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a new age[In numbers]: "; }
				break;
			case 4:
				cout << "Male or Female? [M /F]: ";
				cin >> s1[IDOwner - 1].gender;
				break;
			case 5:
				cout << "Enter a new address: ";
				cin.ignore();
				getline(cin, s1[IDOwner - 1].adress);
				break;
			case 6:
				cout << "Enter new shop name: ";
				cin.ignore();
				getline(cin, s1[IDOwner - 1].shop1.name);
				break;
			case 7:
				cout << "Enter new shop category: ";
				cin.ignore();
				getline(cin, s1[IDOwner - 1].shop1.category);
				break;
			case 8:
				cout << "Enter new shop address: ";
				cin.ignore();
				getline(cin, s1[IDOwner - 1].shop1.address);
				break;

			default:
				system("CLS");
				cout << "<< You entered an Invalid input >>\n";
				break;

			}
			saveInfo();
		}

		else {
			flag = false;
		}
	}
}
void DisplayEditOwner(int&IDOwner) {
	system("CLS");
	cout << "Your new data is : " << endl;
	cout << "Owner's Name: " << s1[IDOwner - 1].name << endl;
	cout << "ID: " << IDOwner << endl;
	cout << "Password: " << s1[IDOwner - 1].password << endl;
	cout << "Age: " << s1[IDOwner - 1].age << endl;
	cout << "Gender: " << s1[IDOwner - 1].gender << endl;
	cout << "Owners's Address: " << s1[IDOwner - 1].adress << endl;
	cout << "Shop's Name: " << s1[IDOwner].shop1.name << endl;
	cout << "Shop's Address: " << s1[IDOwner - 1].shop1.address << endl;
	cout << "Category: " << s1[IDOwner - 1].shop1.category << endl;

}
void CheckCat() {
	system("CLS");
	int NumOfCat = 0;
	cout << "--------------------\n" <<
		"Available categories\n" <<
		"--------------------\n" <<
		"[1] Clothes\n" <<
		"[2] Electronics\n" <<
		"[3] Cars\n" <<
		"[4] Glasses\n" <<
		"Select the number of Category[1-4]: ";
	while (!(cin >> NumOfCat)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter the number of category[1-4]: "; }
	Categories(NumOfCat);
}
void DisplayEdit(int &ID) {
	system("CLS");
	cout << "Your new data is : " << endl;
	cout << "Name: " << Users[ID - 1].Name << endl;
	cout << "ID: " << ID << endl;
	cout << "Password: " << Users[ID - 1].password << endl;
	cout << "Age: " << Users[ID - 1].Age << endl;
	cout << "Gender: " << Users[ID - 1].Gender << endl;
	cout << "Address: " << Users[ID - 1].Address << endl;
}
void Edit(int choice, int& ID) {
	bool flag = true;
	char ans;
	string password;
	while (flag == true) {

		cout << "Do you wish to change something ? [Y / N]: "; cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			system("CLS");
			cout << "------------------\n" << "Edit your profile\n" << "------------------\n";
			cout << "Please select  [ 1)Name - 2)Password - 3)Age - 4)Gender - 5)Address ]" << endl;
			cout << "-->  ";
			while (!(cin >> choice)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1-5]: "; }
			switch (choice) {
			case 1:
				cout << "Enter desired new name: ";
				cin.ignore();
				getline(cin, Users[ID - 1].Name);
				break;
			case 2:

				cout << "Please enter your old password for verification: ";
				cin.ignore();
				getline(cin, password);
				if (password == Users[ID - 1].password) {
					cout << "Enter a new password: ";
					cin.ignore();
					getline(cin, Users[ID - 1].password);
				}
				else {
					cout << "Incorrect password" << endl;
				}
				break;
			case 3:
				cout << "Enter a new age: ";
				while (!(cin >> Users[ID - 1].Age)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a new age[In numbers]: "; }
				break;
			case 4:
				cout << "Male or Female? [M / F]: ";
				cin >> Users[ID - 1].Gender;
				break;
			case 5:
				cout << "Enter a new address: ";
				cin.ignore();
				getline(cin, Users[ID - 1].Address);
				break;

			default:
				system("CLS");
				cout << "<< You entered an Invalid input >>\n";
				break;

			}
			saveInfo();
		}

		else {
			flag = false;
		}
	}

}
void search(string) {
	bool x = true;
	int counter = 0;
	system("CLS");
	cout << "-------------\n" << "Search Engine\n" << "-------------\n";
	cout << "Please enter product name: ";
	cin.ignore();
	getline(cin, NameOfProd);
	for (int i = 0; i < number_of_sellers; i++) {
		for (int j = 0; j < max_num_of_prod; j++) {
			s1[i].shop1.products[j].product_name[0] = tolower(s1[i].shop1.products[j].product_name[0]);
			NameOfProd[0] = tolower(NameOfProd[0]);
			if (s1[i].shop1.products[j].product_name.find(NameOfProd) != string::npos) {
				cout << " Product number: " << s1[i].shop1.products[j].product_num << endl;
				cout << " Product name: " << s1[i].shop1.products[j].product_name << endl;
				cout << " Product quantity: " << s1[i].shop1.products[j].quantity << endl;
				cout << " Product price: " << s1[i].shop1.products[j].price << endl;
				x = false;
			}
		}
	}
	if (x == true) {
		cout << "Out of stock.\n";
	}
}
void Options(int NumOfOptions, int& ID) {
	int choice = 0;

	switch (NumOfOptions) {

	case 1:
		CheckCat();
		break;
	case 2:
		Edit(choice, ID);
		DisplayEdit(ID);
		break;
	case 3:
		search(NameOfProd);
		break;
	case 4:
		view_cart();
		break;
	case 5:
		LogoutUser();
		break;
	}
}
void view_all_shop_products(seller s1[number_of_sellers], int IDOwner)
{
	cout << "Number of products: " << "< " << s1[IDOwner - 1].shop1.num_of_products << " >" << endl;
	for (int i = 0; i < s1[IDOwner - 1].shop1.num_of_products; i++)
	{
		cout << " Product number: " << s1[IDOwner - 1].shop1.products[i].product_num << endl;
		cout << " Product name: " << s1[IDOwner - 1].shop1.products[i].product_name << endl;
		cout << " Product quantity: " << s1[IDOwner - 1].shop1.products[i].quantity << endl;
		cout << " Product price: " << s1[IDOwner - 1].shop1.products[i].price << endl;
		cout << "------------------\n";
	}
}
void owner(int &IDOwner)
{

	char ans1, ans2, ans3;
	int delete_product;
	int what_do_you_want;
	system("CLS");
	cout << "Would you like to : [1] View shop and edit products.\n \t \t    [2] Edit your information.\n \t \t    [3] Logout. " << endl;
	cout << "-->  ";
	while (!(cin >> what_do_you_want)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1 , 2]: "; }
	if (what_do_you_want == 1)
	{
		system("CLS");
		cout << "<< Welcome to your store(" << s1[IDOwner - 1].shop1.name << ") >>" << endl;
		view_all_shop_products(s1, IDOwner);
		cout << " Do you want to add a product [Y / N] ? ";
		cin >> ans1;
		while (ans1 == 'y' || ans1 == 'Y')
		{
			if (ans1 == 'y' || ans1 == 'Y')
			{
				s1[IDOwner - 1].shop1.num_of_products++;
				for (int i = 0; i < s1[IDOwner - 1].shop1.num_of_products; i++)
				{
					if (s1[IDOwner - 1].shop1.products[i].product_num == 0)
					{
						cout << " The product number is : " << i + 1 << endl;
						s1[IDOwner - 1].shop1.products[i].product_num = i + 1;
						cout << "Enter product name: ";
						cin.ignore();
						getline(cin, s1[IDOwner - 1].shop1.products[i].product_name);
						cout << "Enter product quantity: ";
						while (!(cin >> s1[IDOwner - 1].shop1.products[i].quantity)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a quantity: "; }
						cout << "Enter product price: ";
						while (!(cin >> s1[IDOwner - 1].shop1.products[i].price)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a price: "; }
					}
				}
				cout << "Do you want to add another product [Y / N] ? ";
				cin >> ans1;

			}
			saveInfo();
		}
		cout << "Do you want to remove a product [Y / N] ? ";
		cin >> ans2;
		{
			while (ans2 == 'y' || ans2 == 'Y')
			{
				if (ans2 == 'y' || ans2 == 'Y')
				{
					cout << "Which product do you want to remove ? (Enter product number) ";
					while (!(cin >> delete_product)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a product number: "; }
					s1[IDOwner - 1].shop1.products[delete_product - 1].price = s1[IDOwner - 1].shop1.products[delete_product].price;
					s1[IDOwner - 1].shop1.products[delete_product - 1].product_name = s1[IDOwner - 1].shop1.products[delete_product].product_name;
					s1[IDOwner - 1].shop1.products[delete_product - 1].product_num = s1[IDOwner - 1].shop1.products[delete_product].product_num;
					s1[IDOwner - 1].shop1.products[delete_product - 1].quantity = s1[IDOwner - 1].shop1.products[delete_product].quantity;
					s1[IDOwner - 1].shop1.products[delete_product].price = {};
					s1[IDOwner - 1].shop1.products[delete_product].product_name = {};
					s1[IDOwner - 1].shop1.products[delete_product].product_num = {};
					s1[IDOwner - 1].shop1.products[delete_product].quantity = {};
					s1[IDOwner - 1].shop1.num_of_products--;
					cout << "Do you want to remove another product [Y / N] ? ";
					cin >> ans2;
				}
				saveInfo();
			}
		}
		cout << "Do you want to refresh your store [Y / N] ? ";
		cin >> ans3;
		if (ans3 == 'y' || ans3 == 'Y')
		{
			view_all_shop_products(s1, IDOwner);
			con1 = 1;
		}
		else
		{
			cout << "Thank you !" << endl;
			con1 = 1;
		}

	}
	else if (what_do_you_want == 2)
	{
		bool flag = true;
		//char ans;
		int choice = 0;
		EditOwner(choice, IDOwner);
		DisplayEditOwner(IDOwner);

	}
	else if (what_do_you_want == 3) {
		LogoutOwner();
	}
	else {
		owner(IDOwner);
	}
}
void First(int& ID) {
	int NumOfOptions = 0;
	system("CLS");
	cout << "--------------------\n" <<
		"Available options :\n" <<
		"--------------------\n" <<
		"[1] Check Categories\n" <<
		"[2] Edit my profile\n" <<
		"[3] Search for a specific product\n" <<
		"[4] Cart\n" <<
		"[5] Logout\n" <<
		"Select the number of option[1 - 5]: ";
	while (!(cin >> NumOfOptions)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1 - 5]: "; }
	Options(NumOfOptions, ID);

}
void SignIn() {
	int IDL; string Password;
	cout << "Enter ID: ";
	while (!(cin >> IDL)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter your ID: "; }	cout << "Enter Password: "; cin >> Password;
	for (int i = 0; i < 100; i++) {
		if (Users[IDL - 1].password == Password) {
			ID = IDL;
			con1 = 1;
			First(ID);
			break;
		}
		else {
			cout << "Incorrect ID or Password" << endl;
			break;
		}
	}
}
void SignUp() {
	cin.get();
	for (int i = 0; i < 100; i++) {
		if (Users[i].password.empty()) {
			cout << "Please enter your name: ";
			getline(cin, Users[i].Name);
			while (Users[i].Name.length() == 0) { cout << "Invalid Input!\nPlease enter a valid name:"; getline(cin, Users[i].Name); }
			cout << "Please enter your Password: ";
			getline(cin, Users[i].password);
			while (Users[i].password.length() == 0) { cout << "Invalid Input!\nPlease enter a valid password:"; getline(cin, Users[i].password); }
			cout << "Please enter your age: ";
			while (!(cin >> Users[i].Age)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter your age [In numbers]: "; }
			cout << "Please enter your Gender [M / F]: ";
			cin.ignore();
			getline(cin, Users[i].Gender);
			while (Users[i].Gender.length() == 0) { cout << "Invalid Input!\nPlease enter a valid gender[M / F]:"; getline(cin, Users[i].Gender); }
			cout << "Please enter your Address: ";
			getline(cin, Users[i].Address);
			while (Users[i].Address.length() == 0) { cout << "Invalid Input!\nPlease enter a valid address:"; getline(cin, Users[i].Address); }
			cout << "Registeration successful!\n" << endl;
			ID = i + 1;
			cout << "Your ID is: " << "< " << ID << " >" << endl;
			break;
		}
	}
	saveInfo();
	SignIn();
}
void User() {
	int num;
	char condition = 'y';
	while (condition == 'y') {
		if (con1 == 0)
		{
			cout << "Would you like to : [1] Sign In.\n \t \t    [2] Sign Up." << endl;
			cout << "-->  ";
			while (!(cin >> num)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1 , 2]: "; }
			if (num == 1) {
				SignIn();
			}
			else if (num == 2) {
				SignUp();
			}
			else {
				cout << "Please enter a valid number [1 - 2]" << endl;
				User();

			}

		}
		else {
			cout << "Do you wish to return to the home page [Y / N] ?: ";
			cin >> condition;
			if (condition == 'y' || condition == 'Y')
			{
				First(ID);
			}
			else if (condition == 'n' || condition == 'N')
				break;
		}
	}
}
void SignInOwner() {
	int IDOwnerL; string Password;
	cout << "Enter ID: ";
	while (!(cin >> IDOwnerL)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter your ID: "; }
	cout << "Enter Password: ";
	cin >> Password;
	for (int i = 0; i < 100; i++) {
		if (s1[IDOwnerL - 1].password == Password) {
			IDOwner = IDOwnerL;
			con1 = 1;
			owner(IDOwnerL);
			break;
		}
		else {
			cout << "Incorrect ID or Password" << endl;
			break;
		}
	}
}
void AddShop(int &IDOwner) {
	cout << "Please enter shop information: " << endl;;
	cout << "Enter shop name: ";
	getline(cin, s1[IDOwner - 1].shop1.name);
	cout << "Enter shop address: ";
	getline(cin, s1[IDOwner - 1].shop1.address);
	cout << "Enter shop category[Clothes,Electronics,Cars,Glasses]: ";
	getline(cin, s1[IDOwner - 1].shop1.category);
	saveInfo();
	owner(IDOwner);
}
void SignUpOwner() {
	cin.get();
	for (int i = 0; i < 100; i++) {
		if (s1[i].password.empty()) {
			cout << "Please enter your name: ";
			getline(cin, s1[i].name);
			while (s1[i].name.length() == 0) { cout << "Invalid Input!\nPlease enter a valid name:"; getline(cin, s1[i].name); }
			cout << "Please enter your Password: ";
			getline(cin, s1[i].password);
			while (s1[i].password.length() == 0) { cout << "Invalid Input!\nPlease enter a valid password:"; getline(cin, s1[i].password); }
			cout << "Please enter your age: ";
			while (!(cin >> s1[i].age)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter your age [In numbers]: "; }
			cout << "Please enter your Gender [M / F]: ";
			cin.ignore();
			getline(cin, s1[i].gender);
			while (s1[i].gender.length() == 0) { cout << "Invalid Input!\nPlease enter a valid gender[M / F]:"; getline(cin, s1[i].gender); }
			cout << "Please enter your Address: ";
			getline(cin, s1[i].adress);
			while (s1[i].adress.length() == 0) { cout << "Invalid Input!\nPlease enter a valid address:"; getline(cin, s1[i].adress); }
			cout << "Registeration successful!\n" << endl;
			IDOwner = i + 1;
			cout << "Your ID is: " << "< " << IDOwner << " >" << endl;
			break;
		}
	}
	saveInfo();
	AddShop(IDOwner);
}
void readInfo() {
	int i = 0;
	ifstream ownerInfo("OwnerAccounts.txt");
	string temp;
	while (getline(ownerInfo, temp)) {
		s1[i].IDOwner = stoi(temp);
		getline(ownerInfo, s1[i].password);
		getline(ownerInfo, s1[i].name);
		getline(ownerInfo, temp);
		s1[i].age = stoi(temp);
		getline(ownerInfo, temp);
		s1[i].gender = temp[0];
		getline(ownerInfo, s1[i].adress);
		i++;
	}
	ownerInfo.close();
	int j = 0;
	ifstream userInfo("UserAccounts.txt");
	while (getline(userInfo, temp)) {
		Users[j].ID = stoi(temp);
		getline(userInfo, Users[j].password);
		getline(userInfo, Users[j].Name);
		getline(userInfo, temp);
		Users[j].Age = stoi(temp);
		getline(userInfo, temp);
		Users[j].Gender = temp[0];
		getline(userInfo, Users[j].Address);
		j++;
	}
	userInfo.close();
	int	r = 0;
	ifstream shopInfo("ShopData.txt");
	while (getline(shopInfo, temp)) {
		s1[r].shop1.num_of_products = stoi(temp);
		getline(shopInfo, s1[r].shop1.name);
		getline(shopInfo, s1[r].shop1.address);
		getline(shopInfo, s1[r].shop1.category);
		r++;
	}
	shopInfo.close();
	ifstream productInfo("ProductData.txt");
	for (int k = 0; k < 100; k++) {
		for (int w = 0; w < s1[k].shop1.num_of_products; w++) {
			while (getline(productInfo, temp)) {
				s1[k].shop1.products[w].quantity = stoi(temp);
				getline(productInfo, s1[k].shop1.products[w].product_name);
				getline(productInfo, temp);
				s1[k].shop1.products[w].product_num = stoi(temp);
				getline(productInfo, temp);
				s1[k].shop1.products[w].price = stof(temp);
				break;
			}
		}
	}
	productInfo.close();
}
void Owner() {
	int num;
	char condition = 'y';
	while (condition == 'y') {
		if (con1 == 0)
		{

			cout << "Would you like to : [1] Sign In.\n \t \t    [2] Sign Up." << endl;
			cout << "-->  ";
			while (!(cin >> num)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1 , 2]: "; }
			if (num == 1) {
				SignInOwner();

			}
			else if (num == 2) {
				SignUpOwner();
			}
			else {
				cout << "Please enter a valid number[1 - 2] !" << endl;
				Owner();

			}

		}
		else {
			cout << "Do you wish to return to the home page [Y / N] ?: ";
			cin >> condition;
			if (condition == 'y' || condition == 'Y')
			{
				owner(IDOwner);
			}
			else if (condition == 'n' || condition == 'N')
				break;
		}
	}
}
void LogoutUser() {
	char choice;
	con1 = 0;
	cout << "Are you sure you want to logout ? [Y / N]: "; cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		system("CLS");
		User();
	}
	else if (choice == 'N' || choice == 'n') {
		First(ID);
	}
	else {
		cout << "Invalid Input!\n";
		LogoutUser();
	}
}
void LogoutOwner() {
	char choice;
	con1 = 0;
	cout << "Are you sure you want to logout ? [Y / N]: "; cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		system("CLS");
		Owner();
	}
	else if (choice == 'N' || choice == 'n') {
		owner(IDOwner);
	}
	else {
		cout << "Invalid Input!\n";
		LogoutOwner();
	}
}
int main() {
	SetConsoleTitle("Horizon Online Shopping");
	readInfo();
	cout << "\t \t \t \t --------------------------------------\n" <<
		"\t \t \t \t | Welcome to Horizon Online Shopping |\n" <<
		"\t \t \t \t --------------------------------------\n";
	char conditionn = 'y';
	int numb;
	int change = 0;
	while (change == 0) {
		cout << "Please Choose:  [1] User \n\t\t[2] Owner" << endl;
		cout << "-->  ";
		while (!(cin >> numb)) { cin.clear(); cin.ignore(1000, '\n'); cout << "Invalid Input!\nPlease enter a number[1 , 2]: "; }
		if (numb == 1) {
			change = 1;
			User();
			break;
		}
		else if (numb == 2) {
			change = 1;
			Owner();
			break;
		}
		else {
			cout << "Choose [1] or [2] please !" << endl;
		}
	}
	return 0;
	system("pause");
}