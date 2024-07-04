#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
int var = 10;
int fineperday = 1;
map<string, bool> m1;
map<bool, string> m2;
bool has_only_digits(string s)
{
  return s.find_first_not_of("0123456789") == string::npos;
}
bool isDate(string s)
{
  bool ok = true;
  ok = ok and (s.length() == 8);
  ok = ok and (s[0] <= '9' and s[0] >= '0');
  ok = ok and (s[1] <= '9' and s[1] >= '0');
  ok = ok and (s[3] <= '9' and s[3] >= '0');
  ok = ok and (s[4] <= '9' and s[4] >= '0');
  ok = ok and (s[6] <= '9' and s[6] >= '0');
  ok = ok and (s[7] <= '9' and s[7] >= '0');
  ok = ok and (s[2] == s[5] and s[5] == '/');
  int d = s[0] - 48;
  d = d * 10;
  d += s[1] - 48;
  // cout << d << endl;
  ok = ok and (d > 0 and d < 32);
  d = 0;
  d = s[3] - 48;
  d = d * 10;
  d += s[4] - 48;
  // cout << d << endl;
  ok = ok and (d > 0 and d < 13);
  d = 0;
  d = s[6] - 48;
  d = d * 10;
  d += s[7] - 48;
  // cout << d << endl;
  ok = ok and (d > 0 and d < 100);
  return ok;
}
int stoz(string str)
{
  int temp = 0;
  for (int i = 0; i < str.length(); i++)
  {
    temp = temp * 10 + (str[i] - '0');
  }
  return temp;
}
float stof1(string str)
{
  str += ".";
  str += ".";
  float val = 0;
  int cur = 0;
  while (str[cur] != '.')
  {
    int val1 = str[cur] - 48;
    val = val * 10 + val1;
    cur++;
  }
  cur++;
  float val2 = 0;
  int count = 1;
  while (str[cur] != '.')
  {
    int val3 = str[cur] - 48;
    val2 = val2 * 10.0 + val3;
    cur++;
    count *= 10;
  }
  val2 = val2 / count;
  val += val2;
  return val;
}
bool find1(vector<string> &ids, string id)
{
  for (auto id1 : ids)
  {

    if (id1 == id)
      return true;
    cout << " " << endl;
  }
  return false;
}
void carformat()
{
  cout << "model"
       << "\t\t|"
       << "condition"
       << "\t\t|"
       << "price"
       << "\t\t|"
       << "car_id"
       << "\t\t|"
       << "rentee_id"
       << "\t\t|"
       << "return_date"
       << "\t\t|"
       << "Availabiltiy" << endl;
}
void empformat()
{
  cout << "ID"
       << "\t\t|"
       << "name"
       << "\t\t|"
       << "Password"
       << "\t\t|"
       << "Emp-Record"
       << "\t\t|"
       << "No. of Cars rented"
       << "\t\t|"
       << "Dues"
       << "\t\t|"
       << "ids of cars-rented" << endl;
}
void custformat()
{
  cout << "ID"
       << "\t\t|"
       << "name"
       << "\t\t|"
       << "Password"
       << "\t\t|"
       << "Cust-Record"
       << "\t\t|"
       << "No. of Cars rented"
       << "\t\t|"
       << "Dues"
       << "\t\t|"
       << "ids of cars-rented" << endl;
}

string lim(float i)
{
  if (i <= 4)
    return "1";
  if (i <= 7)
    return "2";
  if (i < 10)
    return "3";
  return "4";
}

void DatePlusDays(struct tm *date, int days)
{
  const time_t ONE_DAY = 24 * 60 * 60;
  time_t date_seconds = mktime(date) + (days * ONE_DAY);
  *date = *localtime(&date_seconds);
}
string next_date(string current_date, int inc)
{
  // dd/mm/yy format
  int d1, d2;
  int m1, m2;
  int y1, y2;
  char c;
  d1 = current_date[0] - 48;
  d2 = current_date[1] - 48;
  m1 = current_date[3] - 48;
  m2 = current_date[4] - 48;
  y1 = current_date[6] - 48;
  y2 = current_date[7] - 48;
  d1 = 10 * d1 + d2;
  m1 = 10 * m1 + m2;
  y1 = 10 * y1 + y2;
  struct tm input_date = {0, 0, 12};
  input_date.tm_mday = d1;
  input_date.tm_mon = m1 - 1;
  input_date.tm_year = y1 + 100;

  DatePlusDays(&input_date, inc);
  d1 = input_date.tm_mday;
  m1 = input_date.tm_mon;
  m1++;
  y1 = input_date.tm_year;
  y1 %= 100;
  d2 = d1 % 10;
  d1 = d1 / 10;
  m2 = m1 % 10;
  m1 = m1 / 10;
  // cout << y1 << endl;
  y2 = y1 % 10;
  y1 = y1 / 10;
  // cout << y1 << " " << y2 << endl;
  string next_date = "";
  next_date += d1 + 48;
  next_date += d2 + 48;
  next_date += '/';
  next_date += m1 + 48;
  next_date += m2 + 48;
  next_date += '/';
  next_date += y1 + 48;
  next_date += y2 + 48;
  return next_date;
}
int date_diff(string current_date, string due_date)
{
  int d1, d2, d3, d4;
  int m1, m2, m3, m4;
  int y1, y2, y3, y4;
  char c;
  d1 = current_date[0] - 48;
  d2 = current_date[1] - 48;
  m1 = current_date[3] - 48;
  m2 = current_date[4] - 48;
  y1 = current_date[6] - 48;
  y2 = current_date[7] - 48;
  d1 = 10 * d1 + d2;
  m1 = 10 * m1 + m2;
  y1 = 10 * y1 + y2;
  d3 = due_date[0] - 48;
  d4 = due_date[1] - 48;
  m3 = due_date[3] - 48;
  m4 = due_date[4] - 48;
  y3 = due_date[6] - 48;
  y4 = due_date[7] - 48;
  d3 = 10 * d3 + d4;
  m3 = 10 * m3 + m4;
  y3 = 10 * y3 + y4;
  struct tm input_date = {0, 0, 12};
  input_date.tm_mday = d1;
  input_date.tm_mon = m1 - 1;
  input_date.tm_year = y1 + 100;
  const time_t ONE_DAY = 24 * 60 * 60;
  time_t date_seconds1 = mktime(&input_date);
  struct tm input_date1 = {0, 0, 12};
  input_date1.tm_mday = d3;
  input_date1.tm_mon = m3 - 1;
  input_date1.tm_year = y3 + 100;
  // const time_t ONE_DAY = 24 * 60 * 60;
  time_t date_seconds2 = mktime(&input_date1);
  // cout << current_date << endl;
  // cout << due_date << endl;
  auto diff = date_seconds1 - date_seconds2;
  diff = diff / ONE_DAY;
  // cout << diff << endl;
  return diff;
}
class Car
{
private:
  string model;
  string condition;
  string price;
  bool isAvailable;
  string rentee_id;
  string car_id;
  string return_date; // dd/mm/yy
public:
  static int car_count;

  Car(string model, string condition, string price)
  {
    this->model = model;
    this->condition = condition;
    this->isAvailable = true;
    this->price = price;
    this->rentee_id = "None";
    car_count++;
    std::mt19937_64 gen(std::random_device{}());

    std::uint32_t randomNumber = gen();
    this->car_id = to_string(var);
    var++;
    this->return_date = "NA";
  }
  Car(string model, string condition, string price, string car_id, string rentee_id, string return_date)
  {
    this->model = model;
    this->condition = condition;
    this->isAvailable = true;
    this->price = price;
    this->rentee_id = rentee_id;
    car_count++;
    this->car_id = car_id;
    this->return_date = return_date;
  }

public:
  void update_details(string model, string condition, string price)
  {
    this->model = model;
    this->condition = condition;
    this->isAvailable = true;
    this->price = price;
  }
  void change_status()
  {
    this->isAvailable = !(this->isAvailable);
  }
  bool check_availability()
  {
    return this->isAvailable;
  }
  string getrentee_id()
  {
    return this->rentee_id;
  }
  void setModel(string model)
  {
    this->model = model;
  }
  void setcondition(string condition)
  {
    this->condition = condition;
  }
  void setprice(string price)
  {
    this->price = price;
  }
  void setrenteeid(string id)
  {
    this->rentee_id = id;
  }
  string getcar_id()
  {
    return this->car_id;
  }
  void setcarid(string id)
  {
    this->car_id = id;
  }
  string getreturn_date()
  {
    return this->return_date;
  }
  void setreturndate(string date)
  {
    this->return_date = date;
  }
  void setavailabilty(bool availabilty)
  {
    this->isAvailable = availabilty;
  }
  bool match_id(string id)
  {
    return (this->car_id == id);
  }
  void details()
  {
    // string print_price = to_string(price);
    carformat();
    cout << model << "\t\t" << condition << "\t\t"
         << "$" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << m2["availability"] << endl;
  }
  void limdetails()
  {
    cout << "Model"
         << "\t\t"
         << "Condition"
         << "\t\t"
         << "Price" << endl;
    cout << this->model << " " << this->condition << " "
         << "$" << this->price << " " << endl;
  }
  string getmodel()
  {
    return model;
  }
  string getcondition()
  {
    return condition;
  }
  string getprice()
  {
    return price;
  }
};

int Car::car_count = 0;

class User
{

protected:
  string name;
  string id;
  string password;
  string get_details()
  {
    cout << name << " " << password << endl;
  }
  vector<string> show_available_cars()
  {
  }

public:
  string get_id()
  {
    return id;
  }
  string get_name()
  {
    return name;
  }
  string get_password()
  {
    return password;
  }
  void setid(string id)
  {
    this->id = id;
  }
  void setname(string name)
  {
    this->name = name;
  }
  void setpassword(string password)
  {
    this->password = password;
  }
  bool autheticate(string name, string password)
  {
    return (this->password == password && this->name == name);
  }
  bool match_id(string id)
  {
    return (this->id == id);
  }
};

class Rentee
{
protected:
  vector<string> rented_cars_id;
  string Fine;
  string cars_rented_no;
  string rent_limit;
  float discount;

public:
  bool rent_request(string id, int rentee_type, string rentee_id1, string current_date);
  bool clear_due(int rentee_type, string rentee_id1, string amount);
  bool return_car(string id, int rentee_type, string rentee_id1, string current_date);
  // gets
  string get_rented_cars_no()
  {
    return this->cars_rented_no;
  }
  string get_fine()
  {
    return this->Fine;
  }
  vector<string> get_car_ids()
  {
    return rented_cars_id;
  }
  string get_rent_limit()
  {
    return rent_limit;
  }
  float get_discount()
  {
    return discount;
  }
  // sets
  void set_rented_cars_no(string cars_rented_no)
  {
    this->cars_rented_no = cars_rented_no;
  }
  void set_fine(string fine)
  {
    this->Fine = fine;
  }
  void set_car_ids(vector<string> car_ids)
  {
    this->rented_cars_id = car_ids;
  }
  void set_rent_limit(string rent_limit)
  {
    this->rent_limit = rent_limit;
  }
};

class Employee : public User, public Rentee

{

private:
  string employee_record;

public:
  Employee(string id, string name,
           string password, string employee_record,
           string cars_rented_no, string fine, const vector<string> &cars_rented)
  {
    // id =  id;
    this->id = id;
    this->name = name;
    this->password = password;
    this->cars_rented_no = cars_rented_no;
    this->Fine = fine;
    this->rent_limit = "4";
    // cout << rent_limit << endl;
    this->discount = 0.15;
    int num = stoz(cars_rented_no);
    this->employee_record = employee_record;
    for (int i = 0; i < num; i++)
    {
      this->rented_cars_id.push_back(cars_rented[i]);
    }
  }
  // gets
  string get_employee_record()
  {
    return employee_record;
  }
  void set_employee_record(string employee_record)
  {
    this->employee_record = employee_record;
  }
};

class Customer : public User, public Rentee
{
private:
  string customer_record;

public:
  Customer(string id, string name,
           string password, string customer_record,
           string cars_rented_no, string fine, const vector<string> &cars_rented)
  {
    // id =  id;
    this->id = id;
    this->name = name;
    this->password = password;
    this->cars_rented_no = cars_rented_no;
    this->Fine = fine;
    this->rent_limit = "4";
    this->discount = 0;
    int num = stoz(cars_rented_no);
    for (int i = 0; i < num; i++)
    {
      this->rented_cars_id.push_back(cars_rented[i]);
    }
    this->customer_record = customer_record;
  }
  // gets
  string get_customer_record()
  {
    return customer_record;
  }
  // sets
  void set_customer_record(string customer_record)
  {
    this->customer_record = customer_record;
  }
};

class Manager : public User
{
public:
  void addEmployee(string id, string name, string password);
  void deleteEmployee(string id);
  void ViewAllEmployee();
  void update_employee(string id, int att, string new_val);
  Employee search_employee(string id);
  void addCustomer(string id, string name, string password);
  void deleteCustomer(string id);
  void ViewAllCustomers();
  void update_Customer(string id, int att, string new_val);
  Customer search_Customer(string id);
  void add_car()
  {
    ofstream fio;
    fio.open("cars1.txt", ios::in | ios::out | ios::app);
    if (fio.fail())
    {
      cout << "Error opening file." << endl;
    }
    else
    {
      string model, condition;
      string price, car_id;
      cout << "Enter Car details!!" << endl;
      cout << "Enter model: ";
      cin >> model;
      cout << "Enter condition: ";
      cin >> condition;
      cout << "Enter price: ";
      cin >> price;
      Car car(model, condition, price);
      string rentee_id, return_date;
      car_id = car.getcar_id();
      rentee_id = car.getrentee_id();
      return_date = car.getreturn_date();
      bool ok = true;
      if (condition != "good" and condition != "mid" and condition != "bad")
      {
        cout << "Unsuccessful!! Invalid Condition." << endl;
        ok = false;
      }
      if (!has_only_digits(price))
      {
        cout << "Unsuccessful !! Price can only be a positive integer." << endl;
        ok = false;
      }
      if (ok)
        fio << model << "\t\t" << condition << "\t\t" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t"
            << "Available" << endl;
      fio.close();
    }
  }

  void delete_by_id(int id)
  {
    ifstream fio;
    fio.open("cars1.txt", ios::in);
    if (fio.fail())
    {
      cout << "Error opening file." << endl;
    }
    else
    {
      fio.seekg(0, ios::beg);
      vector<Car> cars;
      bool ok = true;
      while (!fio.eof())
      {

        string model, condition;
        string price1, car_id1;
        int price, car_id;
        string rentee_id, return_date;
        string av;
        fio >> model >> condition;
        fio >> price1 >> car_id1;
        fio >> rentee_id >> return_date;
        fio >> av;
        if (car_id1 == "")
          continue;
        bool availability = false;
        if (av == "Available")
          availability = true;
        Car car(model, condition, price1);
        car.setcarid(car_id1);
        car.setreturndate(return_date);
        car.setrenteeid(rentee_id);
        car.setavailabilty(availability);
        cars.push_back(car);
      }
      int matches = 0;
      string id1 = to_string(id);
      vector<Car> ans;
      ans.clear();

      for (auto car : cars)
      {
        if (car.match_id(id1))
        {
          matches++;
          if (!car.check_availability())
          {
            cout << "Car rented!! Can't delete." << endl;
            ok = false;
          }
        }
        else
        {
          ans.push_back(car);
        }
      }
      fio.close();
      if (!matches)
      {
        cout << "NO MATCH FOUND!" << endl;
      }
      else
      {
        if (!ok)
          return;
        ofstream fio;
        fio.open("cars1.txt", ios::in | ios::out | ios::trunc);
        if (fio.fail())
        {
          cout << "Error opening file." << endl;
        }
        else
        {
          for (auto car : ans)
          {
            string model, condition, price, car_id, rentee_id, return_date, availabilty;
            bool av;
            model = car.getmodel();
            availabilty = "Available";
            condition = car.getcondition();
            price = car.getprice();
            car_id = car.getcar_id();
            rentee_id = car.getrentee_id();
            return_date = car.getreturn_date();
            av = car.check_availability();
            if (!av)
              availabilty = "Unavailable";
            fio << model << "\t\t" << condition << "\t\t" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << availabilty << endl;
          }
          fio.close();
        }
      }
    }
  }

  int search_by_id(int id, int param)
  {
    fstream fio;
    fio.open("cars1.txt", ios::in | ios::out | ios::app);
    if (fio.fail())
    {
      cout << "Error opening file." << endl;
      return -2;
    }
    else
    {
      fio.seekg(0, ios::beg);
      vector<Car> cars;
      while (fio)
      {
        string model, condition;
        string price1, car_id1;
        string rentee_id, return_date;
        string av;
        fio >> model >> condition;
        fio >> price1 >> car_id1;
        fio >> rentee_id >> return_date;
        stringstream str;
        stringstream str1;
        Car car(model, condition, price1);
        car.setcarid(car_id1);
        car.setreturndate(return_date);
        car.setrenteeid(rentee_id);
        cars.push_back(car);
        fio >> av;
        bool availability = false;
        if (av == "Available")
          availability = true;
      }
      int matches = 0;
      string id1 = to_string(id);
      int match_idx = -1;
      int idx = 0;
      for (auto car : cars)
      {

        if (car.match_id(id1))
        {
          matches++;
          if (param == 1)
            car.details();
          match_idx = idx;
        }
        idx++;
      }
      fio.close();
      if (!matches)
      {
        cout << "NO MATCH FOUND!" << endl;
        return -1;
      }
      else
        return match_idx;
    }
  }

  void update_by_id(int idx, int attribute, string new_val)
  {
    fstream fio;
    fio.open("cars1.txt", ios::in | ios::out | ios::app);
    if (fio.fail())
    {
      cout << "Error opening file." << endl;
    }
    else
    {
      fio.seekg(0, ios::beg);
      vector<Car> cars;
      while (fio)
      {
        string model, condition;
        string price1, car_id1;
        string rentee_id, return_date;
        string availabilty;
        fio >> model >> condition;
        fio >> price1 >> car_id1;
        fio >> rentee_id >> return_date;
        fio >> availabilty;
        if (car_id1 == "")
          continue;
        bool av = m1[availabilty];
        Car car(model, condition, price1);
        car.setcarid(car_id1);
        car.setreturndate(return_date);
        car.setrenteeid(rentee_id);
        cars.push_back(car);
        car.setavailabilty(av);
      }
      bool ok = true;
      if (attribute == 0)
      {
        cars[idx].setModel(new_val);
      }
      else if (attribute == 1)
      {
        cars[idx].setcondition(new_val);
        if (new_val != "good" and new_val != "mid" and new_val != "bad")
        {
          cout << "Unsuccessful!! Invalid Condition." << endl;
          ok = false;
        }
      }
      else if (attribute == 2)
      {
        cars[idx].setprice(new_val);
        if (!has_only_digits(new_val))
        {
          cout << "Unsuccessful !! Price can only be a positive integer." << endl;
          ok = false;
        }
      }
      else
      {
        cout << "INVALID INPUT!!" << endl;
      }
      if (!ok)
        return;
      fio.close();
      ofstream fio;
      fio.open("cars1.txt", ios::in | ios::out | ios::trunc);
      if (fio.fail())
      {
        cout << "Error opening file." << endl;
      }
      else
      {
        for (auto car : cars)
        {
          string model, condition, price, car_id, rentee_id, return_date;
          model = car.getmodel();
          condition = car.getcondition();
          price = car.getprice();
          car_id = car.getcar_id();
          rentee_id = car.getrentee_id();
          return_date = car.getreturn_date();
          bool av = car.check_availability();
          string availabilty = m2[av];
          fio << model << "\t\t" << condition << "\t\t" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << availabilty << endl;
        }
        fio.close();
      }
    }
  }
};

void emp_details(Employee employee1)
{
  string id1 = employee1.get_id();
  Manager temp;
  auto employee = temp.search_employee(id1);
  string id, name;
  string password, employee_record;
  string cars_rented_no, fine;
  id = employee.get_id();
  name = employee.get_name();
  password = employee.get_password();
  employee_record = employee.get_employee_record();
  cars_rented_no = employee.get_rented_cars_no();
  fine = employee.get_fine();
  // empformat();
  cout << id << "\t\t" << name << "\t\t" << password << "\t\t" << employee_record << "\t\t" << cars_rented_no << "\t\t"
       << "$" << fine << "\t\t";
  int num = stoz(cars_rented_no);
  auto car_ids = employee.get_car_ids();
  for (auto car_id : car_ids)
  {
    cout << car_id << " ";
  }
  cout << endl;
}

void view_cars(int param)
{
  ifstream fio;
  fio.open("cars1.txt", ios::in);
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
  }
  else
  {
    fio.seekg(0, ios::beg);
    vector<Car> cars;
    int count = 0;
    while (!fio.eof())
    {

      string model, condition;
      string price1, car_id1;
      int price, car_id;
      string rentee_id, return_date;
      string av;
      fio >> model >> condition;
      fio >> price1 >> car_id1;
      fio >> rentee_id >> return_date;
      fio >> av;
      if (car_id1 == "")
        continue;
      bool availability = false;
      if (av == "Available")
        availability = true;
      Car car(model, condition, price1);
      car.setcarid(car_id1);
      car.setreturndate(return_date);
      car.setrenteeid(rentee_id);
      car.setavailabilty(availability);
      if (param and !availability)
        continue;
      cars.push_back(car);
      count++;
    }
    carformat();
    if (!count)
    {
      cout << "NO Cars to display!!" << endl;
    }
    for (auto car : cars)
    {
      string model, condition, price, car_id, rentee_id, return_date;
      model = car.getmodel();
      condition = car.getcondition();
      price = car.getprice();
      car_id = car.getcar_id();
      rentee_id = car.getrentee_id();
      return_date = car.getreturn_date();
      bool av = car.check_availability();
      string availabilty = m2[av];
      cout << model << "\t\t" << condition << "\t\t"
           << "$" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << availabilty << endl;
    }
    fio.close();
  }
}

vector<Employee> empdbopen()
{
  ifstream fio;
  vector<Employee> empdb;
  fio.open("employees1.txt");
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
  }
  else
  {
    fio.seekg(0, ios::beg);

    while (fio)
    {
      string id, name;
      string password, employee_record;
      string cars_rented_no, fine;

      fio >> id >> name >> password >> employee_record >> cars_rented_no >> fine;
      if (id == "")
        continue;
      int num = stoz(cars_rented_no);
      vector<string> car_ids;
      for (int i = 0; i < num; i++)
      {
        string car_id;
        fio >> car_id;
        car_ids.push_back(car_id);
      }
      Employee emp(id, name, password, employee_record, cars_rented_no, fine, car_ids);
      empdb.push_back(emp);
      // cout << emp.get_rent_limit() << endl;
    }
    fio.close();
  }
  return empdb;
}

void writeempdb(const vector<Employee> &emp)
{
  fstream fio;
  fio.open("employees1.txt", ios::in | ios::out | ios::trunc);
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
  }
  else
  {
    for (auto employee : emp)
    {
      string id, name;
      string password, employee_record;
      string cars_rented_no, fine;
      id = employee.get_id();
      name = employee.get_name();
      password = employee.get_password();
      employee_record = employee.get_employee_record();
      cars_rented_no = employee.get_rented_cars_no();
      fine = employee.get_fine();
      fio << id << "\t\t" << name << "\t\t" << password << "\t\t" << employee_record << "\t\t" << cars_rented_no << "\t\t" << fine << "\t\t";
      int num = stoz(cars_rented_no);
      auto car_ids = employee.get_car_ids();
      for (auto car_id : car_ids)
      {
        fio << car_id << " ";
      }
      fio << endl;
    }
    fio.close();
  }
}

void Manager::addEmployee(string id, string name, string password)
{
  auto emp = empdbopen();
  bool ok = true;
  for (auto employee : emp)
  {
    if (employee.match_id(id))
    {
      cout << "Unsuccessful!! Another Employee already has the entered id." << endl;
      ok = false;
    }
    if (employee.autheticate(name, password))
    {
      cout << "Unsuccessful!! Another Employee already has the same username and password" << endl;
      ok = false;
    }
  }
  if (!ok)
    return;
  vector<string> empty;
  id = "e" + id;
  Employee emp1(id, name, password, "10", "0", "0", empty);
  emp.push_back(emp1);
  writeempdb(emp);
}

void Manager::deleteEmployee(string id)
{
  auto emp = empdbopen();
  vector<Employee> emp_new;
  int matches = 0;
  bool ok = true;
  for (auto empl : emp)
  {
    if (empl.match_id(id))
    {
      matches++;
      if (stoz(empl.get_rented_cars_no()))
      {
        cout << "Unsuccessful!! User has rented cars." << endl;
        ok = false;
      }
      if (stoz(empl.get_fine()))
      {
        cout << "Unsuccessful!! User has not cleared his dues." << endl;
        ok = false;
      }
    }
    else
    {
      emp_new.push_back(empl);
    }
  }
  if (!matches)
  {
    cout << "NO MATCH !!" << endl;
  }
  else
  {
    if (!ok)
      writeempdb(emp_new);
  }
}

void Manager::update_employee(string id, int att, string new_val)
{
  auto emp = empdbopen();
  bool ok = true;
  int idx = -1;
  int cur = 0;
  for (auto empl : emp)
  {
    if (empl.match_id(id))
    {
      idx = cur;
    }

    cur++;
  }
  if (idx == -1)
  {
    cout << "NO MATCH !!" << endl;
  }
  else
  {
    if (att == 0)
    {
      for (auto employee : emp)
      {
        if (employee.match_id(new_val))
        {
          cout << "Unsuccessful!! Another Employee with same id." << endl;
          ok = false;
        }
      }
      emp[idx].setid(new_val);
    }
    else if (att == 1)
    {
      emp[idx].setname(new_val);
      for (int i = 0; i < emp.size(); i++)
      {
        if (i == idx)
          continue;
        auto name = emp[idx].get_name();
        auto password = emp[idx].get_password();
        if (emp[i].autheticate(name, password))
        {
          cout << "Unsuccessful!! Another Employee with same name and password." << endl;
          ok = false;
        }
      }
    }
    else if (att == 2)
    {
      emp[idx].setpassword(new_val);
      for (int i = 0; i < emp.size(); i++)
      {
        if (i == idx)
          continue;
        auto name = emp[idx].get_name();
        auto password = emp[idx].get_password();
        if (emp[i].autheticate(name, password))
        {
          cout << "Unsuccessful!! Another Employee with same name and password." << endl;
          ok = false;
        }
      }
    }
    else if (att == 3)
      emp[idx].set_employee_record(new_val);
    else if (att == 4)
      emp[idx].set_fine(new_val);
    else if (att == 5)
      emp[idx].set_rented_cars_no(new_val);
    else if (att == 6)
      emp[idx].set_rented_cars_no(new_val);
    else if (att == 7)
    {
      auto rented_car_ids = emp[idx].get_car_ids();
      rented_car_ids.push_back(new_val);
      auto last = unique(rented_car_ids.begin(), rented_car_ids.end());
      emp[idx].set_car_ids(rented_car_ids);
    }
    else if (att == 8)
    {
      auto rented_car_ids = emp[idx].get_car_ids();
      set<string> temp;
      for (auto car_id : rented_car_ids)
        temp.insert(car_id);
      if (temp.count(new_val))
      {
        auto it = temp.find(new_val);
        temp.erase(new_val);
        rented_car_ids.clear();
        for (auto car_id : temp)
          rented_car_ids.push_back(car_id);
      }
      else
      {
        cout << "Car id not found!!";
      }
    }
    else
    {
      cout << "Invalid input!!" << endl;
    }
    if (ok)
      writeempdb(emp);
  }
}

Employee Manager::search_employee(string id)
{
  auto emp = empdbopen();
  // cout<< id << endl;
  int idx = -1;
  int cur = 0;
  for (auto empl : emp)
  {
    if (empl.match_id(id))
    {
      idx = cur;
    }
    cur++;
  }
  string empty = "";
  vector<string> emptys;
  Employee e(empty, empty, empty, empty, empty, empty, emptys);
  if (idx == -1)
  {
    cout << "NO MATCH !!" << endl;
    return e;
  }
  else
    return emp[idx];
}

vector<Customer> custdbopen()
{
  ifstream fio;
  vector<Customer> custdb;
  fio.open("customers1.txt");
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
  }
  else
  {
    fio.seekg(0, ios::beg);

    while (fio)
    {
      string id, name;
      string password, customer_record;
      string cars_rented_no, fine;

      fio >> id >> name >> password >> customer_record >> cars_rented_no >> fine;
      if (id == "")
        continue;
      int num = stoz(cars_rented_no);
      vector<string> car_ids;
      for (int i = 0; i < num; i++)
      {
        string car_id;
        fio >> car_id;
        car_ids.push_back(car_id);
      }
      Customer cust(id, name, password, customer_record, cars_rented_no, fine, car_ids);
      custdb.push_back(cust);
    }
    fio.close();
  }
  return custdb;
}

void custdetails(Customer cust1)
{
  string id1 = cust1.get_id();
  Manager temp;
  auto cust = temp.search_Customer(id1);
  string id, name;
  string password, customer_record;
  string cars_rented_no, fine;
  id = cust.get_id();
  name = cust.get_name();
  password = cust.get_password();
  customer_record = cust.get_customer_record();
  cars_rented_no = cust.get_rented_cars_no();
  fine = cust.get_fine();
  cout << id << "\t\t" << name << "\t\t" << password << "\t\t" << customer_record << "\t\t" << cars_rented_no << "\t\t"
       << "$" << fine << "\t\t";
  int num = stoz(cars_rented_no);
  auto car_ids = cust.get_car_ids();
  for (auto car_id : car_ids)
  {
    cout << car_id << " ";
  }
  cout << endl;
}

void writecustdb(const vector<Customer> &cust)
{
  fstream fio;
  fio.open("customers1.txt", ios::in | ios::out | ios::trunc);
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
  }
  else
  {
    for (auto customer : cust)
    {
      string id, name;
      string password, customer_record;
      string cars_rented_no, fine;
      id = customer.get_id();
      name = customer.get_name();
      password = customer.get_password();
      customer_record = customer.get_customer_record();
      cars_rented_no = customer.get_rented_cars_no();
      fine = customer.get_fine();
      fio << id << "\t\t" << name << "\t\t" << password << "\t\t" << customer_record << "\t\t" << cars_rented_no << "\t\t" << fine << "\t\t";
      int num = stoz(cars_rented_no);
      auto car_ids = customer.get_car_ids();
      for (auto car_id : car_ids)
      {
        fio << car_id << " ";
      }
      fio << endl;
    }
    fio.close();
  }
}

void Manager::addCustomer(string id, string name, string password)
{
  auto cust = custdbopen();
  bool ok = true;
  for (auto customer : cust)
  {
    if (customer.match_id(id))
    {
      cout << "Unsuccessful!! Another customer already has the entered id." << endl;
      ok = false;
    }
    if (customer.autheticate(name, password))
    {
      cout << "Unsuccessful!! Another customer already has the same username and password" << endl;
      ok = false;
    }
  }
  vector<string> empty;
  id = "c" + id;
  Customer cust1(id, name, password, "10", "0", "0", empty);
  cust.push_back(cust1);
  if (ok)
    writecustdb(cust);
}

void Manager::deleteCustomer(string id)
{
  auto cust = custdbopen();
  vector<Customer> cust_new;
  int matches = 0;
  bool ok = false;
  for (auto custl : cust)
  {
    if (custl.match_id(id))
    {
      matches++;
      if (stoz(custl.get_rented_cars_no()))
      {
        cout << "Unsuccessful!! User has rented cars." << endl;
        ok = false;
      }
      if (stoz(custl.get_fine()))
      {
        cout << "Unsuccessful!! User has not cleared his dues." << endl;
        ok = false;
      }
    }
    else
    {
      cust_new.push_back(custl);
    }
  }
  if (!matches)
  {
    cout << "NO MATCH !!" << endl;
  }
  else
  {
    if (!ok)
      writecustdb(cust_new);
  }
}

void Manager::update_Customer(string id, int att, string new_val)
{
  auto cust = custdbopen();
  int idx = -1;
  int cur = 0;
  bool ok = true;
  for (auto custl : cust)
  {
    if (custl.match_id(id))
    {
      idx = cur;
    }
    cur++;
  }
  if (idx == -1)
  {
    cout << "NO MATCH !!" << endl;
  }
  else
  {
    if (att == 0)
    {
      for (auto customer : cust)
      {
        if (customer.match_id(new_val))
        {
          cout << "Unsuccessful!! Another customer with same id." << endl;
          ok = false;
        }
      }
      cust[idx].setid(new_val);
    }
    else if (att == 1)
    {
      for (int i = 0; i < cust.size(); i++)
      {
        if (i == idx)
          continue;
        auto name = cust[idx].get_name();
        auto password = cust[idx].get_password();
        if (cust[i].autheticate(name, password))
        {
          cout << "Unsuccessful!! Another customer with same name and password." << endl;
          ok = false;
        }
      }
      cust[idx].setname(new_val);
    }
    else if (att == 2)
    {
      for (int i = 0; i < cust.size(); i++)
      {
        if (i == idx)
          continue;
        auto name = cust[idx].get_name();
        auto password = cust[idx].get_password();
        if (cust[i].autheticate(name, password))
        {
          cout << "Unsuccessful!! Another customer with same name and password." << endl;
          ok = false;
        }
      }
      cust[idx].setpassword(new_val);
    }
    else if (att == 3)
      cust[idx].set_customer_record(new_val);
    else if (att == 4)
      cust[idx].set_fine(new_val);
    else if (att == 5)
      cust[idx].set_rented_cars_no(new_val);
    else if (att == 6)
      cust[idx].set_rented_cars_no(new_val);
    else if (att == 7)
    {
      auto rented_car_ids = cust[idx].get_car_ids();
      rented_car_ids.push_back(new_val);
      cust[idx].set_car_ids(rented_car_ids);
    }
    else if (att == 8)
    {
      auto rented_car_ids = cust[idx].get_car_ids();
      set<string> temp;
      for (auto car_id : rented_car_ids)
        temp.insert(car_id);
      if (temp.count(new_val))
      {
        auto it = temp.find(new_val);
        temp.erase(new_val);
        rented_car_ids.clear();
        for (auto car_id : temp)
          rented_car_ids.push_back(car_id);
      }
      else
      {
        cout << "Car id not found!!";
      }
    }
    else
    {
      cout << "Invalid input!!" << endl;
    }
    if (!ok)
      writecustdb(cust);
  }
}

void Manager ::ViewAllEmployee()
{
  auto emp = empdbopen();
  empformat();
  for (auto employee : emp)
  {
    emp_details(employee);
  }
}
void Manager ::ViewAllCustomers()
{
  auto cust = custdbopen();
  custformat();
  for (auto customer : cust)
  {
    custdetails(customer);
  }
}
Customer Manager::search_Customer(string id)
{
  auto cust = custdbopen();

  int idx = -1;
  int cur = 0;
  for (auto custl : cust)
  {
    if (custl.match_id(id))
    {
      idx = cur;
    }
    cur++;
  }
  string empty = "";
  vector<string> emptys;
  Customer c(empty, empty, empty, empty, empty, empty, emptys);
  if (idx == -1)
  {
    cout << "NO MATCH !!" << endl;
    return c;
  }
  else
    return cust[idx];
}
bool Rentee::clear_due(int rentee_type, string rentee_id1, string amount)
{
  string fine;
  if (rentee_type == 1)
  {
    Manager temp3;
    auto emp = temp3.search_employee(rentee_id1);
    fine = emp.get_fine();
  }
  else if (rentee_type == 2)
  {
    Manager temp3;
    auto cust = temp3.search_Customer(rentee_id1);
    fine = cust.get_fine();
  }
  int Fine = stoz(fine);
  int amt = stoz(amount);
  if (amt <= 0)
  {
    cout << "Invalid amount entered!!" << endl;
    return false;
  }
  if (Fine < amt)
  {
    cout << "Amount more than Dues !!" << endl;
  }
  else
  {
    Fine = Fine - amt;
    fine = to_string(Fine);
    Manager temp4;
    if (rentee_type == 1)
      temp4.update_employee(rentee_id1, 4, fine);
    else if (rentee_type == 2)
      temp4.update_Customer(rentee_id1, 4, fine);
    else
    {
      cout << "QuiTT!!" << endl;
    }
  }
}
bool Rentee::rent_request(string id, int rentee_type, string rentee_id1, string current_date)
{
  Manager temp2;
  int crno;
  int rent_lim;
  if (rentee_type == 1)
  {
    Manager temp3;
    auto emp = temp3.search_employee(rentee_id1);
    auto cars_rented_no1 = emp.get_rented_cars_no();
    auto user_record = stof1(emp.get_employee_record());
    auto rent_limit = lim(user_record);
    rent_lim = stoz(rent_limit);
    crno = stoz(cars_rented_no1);
  }
  else if (rentee_type == 2)
  {
    Manager temp3;
    auto emp = temp3.search_employee(rentee_id1);
    auto cars_rented_no1 = emp.get_rented_cars_no();
    auto user_record = stof1(emp.get_employee_record());
    auto rent_limit = lim(user_record);
    rent_lim = stoz(rent_limit);
    crno = stoz(cars_rented_no1);
  }
  // cout << rent_limit << endl;
  if (crno >= rent_lim)
  {
    cout << "Cannot rent anymore cars!! You are at rent limit" << endl;
    return false;
  }
  fstream fio;
  fio.open("cars1.txt", ios::in | ios::out | ios::app);
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
    return false;
  }
  else
  {
    fio.seekg(0, ios::beg);
    vector<Car> cars;
    string price2;
    while (fio)
    {
      string model, condition;
      string price1, car_id1;
      int price, return_date1;
      string rentee_id, return_date;
      string availabilty;
      fio >> model >> condition;
      fio >> price1 >> car_id1;
      fio >> rentee_id >> return_date;
      fio >> availabilty;
      if (car_id1 == "")
        continue;
      Car car(model, condition, price1);
      car.setcarid(car_id1);
      car.setreturndate(return_date);
      car.setrenteeid(rentee_id);
      bool av = m1[availabilty];
      car.setavailabilty(av);
      cars.push_back(car);
    }
    int idx = -1;
    int cur = 0;
    for (auto car : cars)
    {
      if (car.match_id(id))
      {
        idx = cur;
      }
      cur++;
    }
    fio.close();
    // cout << idx << endl;
    if (idx == -1)
    {
      cout << "NO MATCH FOUND!" << endl;
      return false;
    }
    else
    {
      if (!cars[idx].check_availability())
      {
        cout << "Car Unavailable!!" << endl;
        return false;
      }
      ofstream fio;
      price2 = cars[idx].getprice();
      fio.open("cars1.txt", ios::in | ios::out | ios::trunc);
      cars[idx].setrenteeid(rentee_id1);
      string due_date = next_date(current_date, 7); // next_date(current_date)
      cout << "Due date : " << due_date << endl;
      cars[idx].setreturndate(due_date);
      cars[idx].setavailabilty(false);
      if (fio.fail())
      {
        cout << "Error opening file." << endl;
      }
      else
      {
        for (auto car : cars)
        {
          string model, condition, price, car_id, rentee_id, return_date;
          model = car.getmodel();
          condition = car.getcondition();
          price = car.getprice();
          car_id = car.getcar_id();
          rentee_id = car.getrentee_id();
          return_date = car.getreturn_date();
          bool av = car.check_availability();
          string availabilty = m2[av];
          fio << model << "\t\t" << condition << "\t\t" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << availabilty << endl;
        }
        fio.close();
      }
    }
    if (rentee_type == 1)
    {
      Manager m;
      auto employee = m.search_employee(rentee_id1);
      int num = stoz(cars_rented_no);
      num++;
      cars_rented_no = to_string(num);
      auto emp = empdbopen();
      auto idx = -1;
      int cur = 0;
      for (auto employee : emp)
      {
        if (employee.match_id(rentee_id1))
          idx = cur;
        cur++;
      }
      if (idx == -1)
      {
        cout << "QUITT!!" << endl;
        return false;
      }
      emp[idx].set_rented_cars_no(cars_rented_no);
      auto car_ids = emp[idx].get_car_ids();
      auto fine = emp[idx].get_fine();
      int fine1 = stoz(fine);
      fine1 += stoz(price2);
      fine = to_string(fine1);
      emp[idx].set_fine(fine);
      car_ids.push_back(id);
      auto last = unique(car_ids.begin(), car_ids.end());
      emp[idx].set_car_ids(car_ids);
      writeempdb(emp);
    }
    else if (rentee_type == 2)
    {
      Manager m;
      auto customer = m.search_Customer(rentee_id1);
      int num = stoz(cars_rented_no);
      num++;
      cars_rented_no = to_string(num);
      auto cust = custdbopen();
      auto idx = -1;
      int cur = 0;
      for (auto customer : cust)
      {
        if (customer.match_id(rentee_id1))
          idx = cur;
        cur++;
      }
      if (idx == -1)
      {
        cout << "QUITT!!" << endl;
        return false;
      }

      cust[idx].set_rented_cars_no(cars_rented_no);
      auto car_ids = cust[idx].get_car_ids();
      car_ids.push_back(id);
      auto last = unique(car_ids.begin(), car_ids.end());
      cust[idx].set_car_ids(car_ids);
      writecustdb(cust);
    }
    return true;
  }
}

bool Rentee ::return_car(string id, int rentee_type, string rentee_id1, string current_date)
{
  vector<string> car_ids;
  bool ok = true;
  if (rentee_type == 1)
  {
    auto emp = empdbopen();
    int matches = 0;
    for (auto employee : emp)
    {
      // cout << rentee_id1 << endl;
      if (employee.match_id(rentee_id1))
        car_ids = employee.get_car_ids();
    }
    if (!matches)
      ok = false;
  }
  else if (rentee_type == 2)
  {
    auto cust = custdbopen();
    int matches = 0;
    for (auto customer : cust)
    {
      if (customer.match_id(rentee_id1))
        car_ids = customer.get_car_ids();
    }
    if (!matches)
      ok = false;
  }
  // for (auto id1 : car_ids)
  // {
  //   cout << id1 << endl;
  // }

  if (!find1(car_ids, id))
  {
    cout << "User has not rented this car!!" << endl;
    return false;
  }
  fstream fio;
  string due_date;
  fio.open("cars1.txt", ios::in | ios::out | ios::app);
  if (fio.fail())
  {
    cout << "Error opening file." << endl;
    return false;
  }
  else
  {
    fio.seekg(0, ios::beg);
    vector<Car> cars;
    while (fio)
    {
      string model, condition;
      string price1, car_id1;
      int price, return_date1;
      string rentee_id, return_date;
      string availabilty;
      fio >> model >> condition;
      fio >> price1 >> car_id1;
      fio >> rentee_id >> return_date;
      fio >> availabilty;
      if (car_id1 == "")
        continue;
      Car car(model, condition, price1);
      car.setcarid(car_id1);
      car.setreturndate(return_date);
      car.setrenteeid(rentee_id);
      bool av = m1[availabilty];
      car.setavailabilty(av);
      cars.push_back(car);
    }
    int idx = -1;
    int cur = 0;
    for (auto car : cars)
    {
      if (car.match_id(id))
      {
        idx = cur;
      }
      cur++;
    }
    fio.close();

    if (idx == -1)
    {
      cout << "NO Car Found With this Id!" << endl;
      return false;
    }
    cars[idx].setavailabilty("Available");
    cars[idx].setrenteeid("None");
    due_date = cars[idx].getreturn_date();
    cars[idx].setreturndate("NA");
    ofstream fio;
    fio.open("cars1.txt", ios::in | ios::out | ios::trunc);
    if (fio.fail())
    {
      cout << "Error opening file." << endl;
    }
    else
    {
      for (auto car : cars)
      {
        string model, condition, price, car_id, rentee_id, return_date;
        model = car.getmodel();
        condition = car.getcondition();
        price = car.getprice();
        car_id = car.getcar_id();
        rentee_id = car.getrentee_id();
        return_date = car.getreturn_date();
        bool av = car.check_availability();
        string availabilty = m2[av];
        fio << model << "\t\t" << condition << "\t\t" << price << "\t\t" << car_id << "\t\t" << rentee_id << "\t\t" << return_date << "\t\t" << availabilty << endl;
      }
      fio.close();
    }
  }

  if (rentee_type == 1)
  {
    Manager m;
    auto employee = m.search_employee(rentee_id1);
    int num = stoz(cars_rented_no);
    num--;
    cars_rented_no = to_string(num);
    auto emp = empdbopen();
    auto idx = -1;
    int cur = 0;
    for (auto employee : emp)
    {
      if (employee.match_id(rentee_id1))
        idx = cur;
      cur++;
    }
    if (idx == -1)
    {
      cout << "QUITT!!" << endl;
      return false;
    }
    emp[idx].set_rented_cars_no(cars_rented_no);
    auto car_ids = emp[idx].get_car_ids();
    auto it = find(car_ids.begin(), car_ids.end(), id);
    car_ids.erase(it);
    auto last = unique(car_ids.begin(), car_ids.end());
    auto late = date_diff(current_date, due_date);
    late = max(0, late);
    auto f = 0;
    f += late * fineperday;
    // cout << late << endl;
    float f1 = f;
    f1 = f1 * (1 - emp[idx].get_discount());
    f = floor(f1);
    f1 = f1 / 20;
    float emprecord = stof1(emp[idx].get_employee_record());
    emprecord -= f1;
    if (emprecord <= 1)
      emprecord = 1;
    if (emprecord > 10)
      emprecord = 10;
    emp[idx].set_employee_record(to_string(emprecord));
    f += stoz(emp[idx].get_fine());
    string fine = to_string(f);
    string limit = lim(emprecord);
    emp[idx].set_fine(fine);
    emp[idx].set_rent_limit(limit);
    emp[idx].set_car_ids(car_ids);
    writeempdb(emp);
  }
  else if (rentee_type == 2)
  {
    Manager m;
    auto customer = m.search_Customer(rentee_id1);
    int num = stoz(cars_rented_no);
    num--;
    cars_rented_no = to_string(num);
    auto cust = custdbopen();
    auto idx = -1;
    int cur = 0;
    for (auto customer : cust)
    {
      if (customer.match_id(rentee_id1))
        idx = cur;
      cur++;
    }
    if (idx == -1)
    {
      cout << "QUITT!!" << endl;
      return false;
    }
    cust[idx].set_rented_cars_no(cars_rented_no);
    auto car_ids = cust[idx].get_car_ids();
    auto it = find(car_ids.begin(), car_ids.end(), id);
    car_ids.erase(it);
    auto last = unique(car_ids.begin(), car_ids.end());
    auto late = date_diff(current_date, due_date);
    auto f = 0;
    f += late * fineperday;
    float f1 = f;
    f1 = f1 * (1 - cust[idx].get_discount());
    f = floor(f1);
    f1 = f1 / 20; // for setting cust record
    float custrecord = stof1(cust[idx].get_customer_record());
    custrecord -= f1;
    if (custrecord <= 1)
      custrecord = 1;
    if (custrecord > 10)
      custrecord = 10;
    cust[idx].set_customer_record(to_string(custrecord));
    f += stoz(cust[idx].get_fine());
    string fine = to_string(f);
    cust[idx].set_fine(fine);
    string limit = lim(custrecord);
    cust[idx].set_rent_limit(limit);
    cust[idx].set_car_ids(car_ids);
    writecustdb(cust);
  }
}

string getuserid(string name, string password, int user_type)
{
  auto cust = custdbopen();
  auto emp = empdbopen();
  int idx = -1;
  if (user_type == 1)
  {
    idx = -1;
    for (int i = 0; i < emp.size(); i++)
    {
      if (emp[i].autheticate(name, password))
      {
        idx = i;
        return emp[i].get_id();
      }
    }
  }
  if (user_type == 2)
  {
    idx = -1;
    for (int i = 0; i < cust.size(); i++)
    {
      if (cust[i].autheticate(name, password))
      {
        idx = i;
        return cust[i].get_id();
      }
    }
  }
  if (idx == -1)
  {
    cout << "User_not_found!!" << endl;
    return "NA";
  }
}

int32_t main()
{
  cout << "\t\t\t\t Welcome to Car rental System" << endl;
  m2[true] = "Available";
  m1["Available"] = true;
  m2[false] = "Unavailable";
  m1["Unavailable"] = false;
  string choice = "0";
  while (choice != "4")
  {
    cout << "Enter as manager (1) : " << endl;
    cout << "Enter as employee (2) : " << endl;
    cout << "Enter as  customer (3) : " << endl;
    cout << "Exit  (4) :" << endl;
    cin >> choice;
    cout << endl;
    cout << endl;
    if (choice == "1")
    {

      cout << "Hello Manager" << endl;
      string manager_choice = "0";
      while (manager_choice != "7")
      {
        cout << endl;
        cout << "Manage Cars (1) : " << endl;
        cout << "Manage Employees (2) : " << endl;
        cout << "Manage Customers (3) : " << endl;
        cout << "View Cars (4) : " << endl;
        cout << "View All Employees (5) : " << endl;
        cout << "View All Customers (6) : " << endl;
        cout << "Exit (7) : " << endl;
        cin >> manager_choice;

        Manager M;
        if (manager_choice == "1")
        {
          string car_choice = "-1";
          cout << "Add a car (1) : " << endl;
          cout << "Search car by id (2) : " << endl;
          cout << "Delete car by id (3) : " << endl;
          cout << "Update Car details (4) : " << endl;
          cin >> car_choice;
          cout << endl;
          cout << endl;
          if (car_choice == "1")
          {
            M.add_car();
          }
          else if (car_choice == "2")
          {
            string id;
            cout << "Enter car id: ";
            cin >> id;
            while (!has_only_digits(id))
            {
              cout << "car id can only be a positive integer" << endl;
              cin >> id;
            }
            auto temp = stoz(id);
            M.search_by_id(temp, 1);
          }
          else if (car_choice == "3")
          {
            string id;
            cout << "Enter car id: ";
            cin >> id;
            while (!has_only_digits(id))
            {
              cout << "car id can only be a positive integer" << endl;
              cin >> id;
            }
            auto temp = stoz(id);
            M.delete_by_id(temp);
          }
          else if (car_choice == "4")
          {
            string id;
            cout << "Enter car id: ";
            cin >> id;
            while (!has_only_digits(id))
            {
              cout << "car id can only be a positive integer" << endl;
              cin >> id;
            }
            auto temp = stoz(id);
            int idx = M.search_by_id(temp, 0);
            if (idx >= 0)
            {
              cout << "Update car model (0) : " << endl;
              cout << "Update car condition (1) : " << endl;
              cout << "Update car price (2) : " << endl;
              string upd_choice = "-1";
              cout << "Enter update choice " << endl;
              cin >> upd_choice;
              if (1)
              {
                cout << "Enter new value : ";
                string new_val;
                cin >> new_val;
                int att;
                if (upd_choice == "0")
                  att = 0;
                if (upd_choice == "1")
                  att = 1;
                if (upd_choice == "2")
                  att = 2;
                M.update_by_id(idx, att, new_val);
              }
              else
              {
                cout << "Invalid Input" << endl;
              }
            }
          }
          else
          {
            cout << "Invalid" << endl;
          }
        }
        else if (manager_choice == "2")
        {
          string me_choice = "0";
          while (me_choice != "5")
          {
            cout << endl;
            cout << "Add Employee (1) : " << endl;
            cout << "Delete Employee (2) : " << endl;
            cout << "Update Employee (3) : " << endl;
            cout << "Search Employee (4) : " << endl;
            cout << "Exit (5) : " << endl;

            cin >> me_choice;
            if (me_choice == "1")
            {
              string id, name, password;
              cout << "Enter employee id : ";
              cin >> id;
              cout << "Enter employee name : ";
              cin >> name;
              cout << "Enter employee password : ";
              cin >> password;
              M.addEmployee(id, name, password);
            }
            else if (me_choice == "2")
            {
              string id;
              cout << "Enter employee id : ";
              cin >> id;
              M.deleteEmployee(id);
            }
            else if (me_choice == "3")
            {
              string id;
              cout << "Enter employee id : ";
              cin >> id;
              cout << "Update Employee name (2) : " << endl;
              cout << "Update Employee password (3) : " << endl;
              string temp;
              cin >> temp;
              while (!has_only_digits(temp))
              {
                cout << "Please Enter a positive integer!!" << endl;
                cin >> temp;
              }
              int upd_choice = stoz(temp);
              string new_val;
              cout << "Enter new value : ";
              cin >> new_val;
              if (upd_choice >= 2 and upd_choice <= 4)
                M.update_employee(id, upd_choice - 1, new_val);
              else
              {
                cout << "INVALID INPUT!!" << endl;
              }
            }
            else if (me_choice == "4")
            {
              string id;
              cout << "Enter employee id" << endl;
              cin >> id;
              auto emp = M.search_employee(id);
              empformat();
              emp_details(emp);
              cout << endl;
            }
            else if (me_choice == "5")
            {
              break;
            }
            else
            {
              cout << "INVALID!!" << endl;
            }
          }
        }
        else if (manager_choice == "3")
        {
          string mc_choice = "0";
          while (mc_choice != "5")
          {
            cout << endl;
            cout << "Add Customer (1) : " << endl;
            cout << "Delete Customer (2) : " << endl;
            cout << "Update Customer (3) : " << endl;
            cout << "Search Customer (4) : " << endl;
            cout << "Exit (5) : " << endl;

            cin >> mc_choice;
            if (mc_choice == "1")
            {
              string id, name, password;
              cout << "Enter Customer id : ";
              cin >> id;
              cout << "Enter Customer name : ";
              cin >> name;
              cout << "Enter Customer password : ";
              cin >> password;
              M.addCustomer(id, name, password);
            }
            else if (mc_choice == "2")
            {
              string id;
              cout << "Enter Customer id : ";
              cin >> id;
              M.deleteCustomer(id);
            }
            else if (mc_choice == "3")
            {
              string id;
              cout << "Enter customer id : ";
              cin >> id;
              cout << "Update Customer name (2) : " << endl;
              cout << "Update customer password (3) : " << endl;
              int upd_choice;
              string temp;
              cin >> temp;
              while (!has_only_digits(temp))
              {
                cout << "Please Enter a positive integer!!" << endl;
                cin >> temp;
              }
              upd_choice = stoz(temp);
              string new_val;
              cout << "Enter new value : ";
              cin >> new_val;
              if (upd_choice <= 3 and upd_choice >= 2)
                M.update_Customer(id, upd_choice - 1, new_val);
              else
              {
                cout << "Wrong input!!" << endl;
              }
            }
            else if (mc_choice == "4")
            {
              string id;
              cout << "Enter customer id" << endl;
              cin >> id;
              auto emp = M.search_Customer(id);
              custdetails(emp);
              cout << endl;
            }
            else if (mc_choice == "5")
            {
              break;
            }
            else
            {
              cout << "INVALID!!" << endl;
            }
          }
        }
        else if (manager_choice == "4")
        {
          string view_choice = "-1";
          cout << "View all cars (0) : " << endl;
          cout << "View available cars (1) : " << endl;
          cout << "Exit (2) : " << endl;
          cin >> view_choice;
          if (view_choice == "0")
            view_cars(0);
          else if (view_choice == "1")
            view_cars(1);
          else if (view_choice == "2")
            continue;
          else
          {
            cout << "INVALID1 !! " << endl;
          }
        }
        else if (manager_choice == "5")
        {
          M.ViewAllEmployee();
        }
        else if (manager_choice == "6")
        {
          M.ViewAllCustomers();
        }
        else if (manager_choice == "7")
        {
          break;
        }
        else
        {
          cout << "INVALID!!" << endl;
        }
      }
    }
    else if (choice == "2")
    {
      string emp_choice = "0";

      int login = 0;
      int exit = 0;
      string id = "NA";
      while (!exit and !login)
      {
        cout << "Login(1) : " << endl;
        cout << "exit(2) : " << endl;
        cin >> emp_choice;

        if (emp_choice == "1")
        {
          string user_name, password;
          cout << "Enter user name : ";
          cin >> user_name;
          cout << "Enter Password : ";
          cin >> password;
          id = getuserid(user_name, password, 1);
          if (id != "NA")
            login = 1;
          // cout << id << endl;
        }
        else if (emp_choice == "2")
        {
          exit = 1;
        }
      }
      if (exit)
        continue;
      Manager temp;
      auto emp = temp.search_employee(id);
      auto name = emp.get_name();
      emp_choice = -1;
      cout << "Hello " << name << endl;
      while (emp_choice != "7")
      {
        cout << "Rent request (1): " << endl;
        cout << "Return car (2) : " << endl;
        cout << "Clear due (3) : " << endl;
        cout << "View all cars (4) : " << endl;
        cout << "View available cars (5) : " << endl;
        cout << "View your details (6) : " << endl;
        cout << "Exit (7) : " << endl;
        cin >> emp_choice;
        if (emp_choice == "1")
        {
          string car_id, current_date;
          cout << "Enter car id : " << endl;
          cin >> car_id;
          cout << "Enter current date (dd/mm/yy) : " << endl;
          cin >> current_date;
          while (!isDate(current_date))
          {
            cout << "Enter date in correct format!!" << endl;
            cin >> current_date;
          }
          // cout << emp.get_name() << endl;
          emp.rent_request(car_id, 1, id, current_date);
        }
        else if (emp_choice == "2")
        {
          string car_id, current_date;
          cout << "Enter car id : " << endl;
          cin >> car_id;
          cout << "Enter current date (dd/mm/yy) : " << endl;
          cin >> current_date;
          while (!isDate(current_date))
          {
            cout << "Enter date in correct format!!" << endl;
            cin >> current_date;
          }
          emp.return_car(car_id, 1, id, current_date);
        }
        else if (emp_choice == "3")
        {
          cout << "Enter amount to be cleared!! : ";
          string amt;

          string temp;
          cin >> temp;
          while (!has_only_digits(temp))
          {
            cout << "Please Enter a positive integer!!" << endl;
            cin >> temp;
          }
          amt = temp;
          emp.clear_due(1, id, amt);
        }
        else if (emp_choice == "4")
        {
          view_cars(0);
        }
        else if (emp_choice == "5")
        {
          view_cars(1);
        }
        else if (emp_choice == "6")
        {
          empformat();
          emp_details(emp);
        }
        else if (emp_choice == "7")
        {
          break;
        }
        else
        {
          cout << "INVALID !!" << endl;
        }
      }
    }
    else if (choice == "3")
    {
      string cust_choice = "0";

      int login = 0;
      int exit = 0;
      string id = "NA";
      while (!exit and !login)
      {
        cout << "Login(1) : " << endl;
        cout << "exit(2) : " << endl;
        cin >> cust_choice;

        if (cust_choice == "1")
        {
          string user_name, password;
          cout << "Enter user name : ";
          cin >> user_name;
          cout << "Enter Password : ";
          cin >> password;
          id = getuserid(user_name, password, 2);
          if (id != "NA")
            login = 1;
          // cout << id << endl;
        }
        else if (cust_choice == "2")
        {
          exit = 1;
        }
      }
      if (exit)
        continue;
      Manager temp;
      auto cust = temp.search_Customer(id);
      auto name = cust.get_name();
      cust_choice = -1;
      cout << "Hello " << name << endl;
      while (cust_choice != "7")
      {
        cout << "Rent request (1): " << endl;
        cout << "Return car (2) : " << endl;
        cout << "Clear due (3) : " << endl;
        cout << "View all cars (4) : " << endl;
        cout << "View available cars (5) : " << endl;
        cout << "View your details (6) : " << endl;
        cout << "Exit (7) : " << endl;
        cin >> cust_choice;
        if (cust_choice == "1")
        {
          string car_id, current_date;
          cout << "Enter car id : " << endl;
          cin >> car_id;
          cout << "Enter current date (dd/mm/yy) : " << endl;
          cin >> current_date;
          while (!isDate(current_date))
          {
            cout << "Enter date in correct format!!" << endl;
            cin >> current_date;
          }
          // cout << emp.get_name() << endl;
          cust.rent_request(car_id, 2, id, current_date);
        }
        else if (cust_choice == "2")
        {
          string car_id, current_date;
          cout << "Enter car id : " << endl;
          cin >> car_id;
          cout << "Enter current date (dd/mm/yy) : " << endl;
          cin >> current_date;
          while (!isDate(current_date))
          {
            cout << "Enter date in correct format!!" << endl;
            cin >> current_date;
          }
          cust.return_car(car_id, 2, id, current_date);
        }
        else if (cust_choice == "3")
        {
          cout << "Enter amount to be cleared!! : ";
          string amt;
          string temp;
          cin >> temp;
          while (!has_only_digits(temp))
          {
            cout << "Please Enter a positive integer!!" << endl;
            cin >> temp;
          }
          amt = temp;
          cust.clear_due(2, id, amt);
        }
        else if (cust_choice == "4")
        {
          view_cars(0);
        }
        else if (cust_choice == "5")
        {
          view_cars(1);
        }
        else if (cust_choice == "6")
        {
          custformat();
          custdetails(cust);
        }
        else if (cust_choice == "7")
        {
          break;
        }
        else
        {
          cout << "INVALID !! " << endl;
        }
      }
    }
    else if (choice == "4")
    {
      cout << endl;
    }
    else
    {

      cout << "Invalid input" << endl;
    }
  }
}
