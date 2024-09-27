import java.util.Scanner;
class Car {
    private int CarType;
    private int select;
    private double hours;
    private double payment;
    private String carname;
    Scanner cartype = new Scanner(System.in);

    void carRental() {
        while (true) {
            System.out.println("\n...Welcome to Rent and Return car platform...\n");
            System.out.println("1) Rent Car");
            System.out.println("2) Return Car");
            System.out.println("3) Exit to Main Menu");
            System.out.print("Enter choice: ");
            select = cartype.nextInt();

            if (select == 1) {
                RentCar();
            } else if (select == 2) {
                ReturnCar();
            } else if (select == 3) {
                break; // exit to main menu
            } else {
                System.out.println("Invalid Choice");
            }
        }
    }

    void RentCar() {
        while (true) {
            System.out.println("Select the car type you filled on your customer Detail to rent.");
            System.out.println("1) BMW");
            System.out.println("2) Lamborghini");
            System.out.println("3) Volkswagen");
            System.out.println("4) Honda");
            System.out.println("5) Mercedes Benz");
            System.out.println("6) Jeep");
            System.out.println("7) Back to Main Menu");
            System.out.print("Enter Choice: ");
            CarType = cartype.nextInt();

            if (CarType >= 1 && CarType <= 6) {
                double Cost_Rent_Per_hour;
                switch (CarType) {
                    case 1: Cost_Rent_Per_hour = 3578.345; break;
                    case 2: Cost_Rent_Per_hour = 5578.315; break;
                    case 3: Cost_Rent_Per_hour = 2578.955; break;
                    case 4: Cost_Rent_Per_hour = 1778.245; break;
                    case 5: Cost_Rent_Per_hour = 4578.985; break;
                    case 6: Cost_Rent_Per_hour = 3978.542; break;
                    default: continue; // shouldn't reach here
                }

                System.out.print("Enter period (hours): ");
                hours = cartype.nextDouble();
                double TotalCost = Cost_Rent_Per_hour * hours;
                System.out.println("Total cost: " + TotalCost + " /=");
                System.out.println("\n..Make Payment..");
                System.out.print("Please make payment to rent the choosen Car:");
                payment = cartype.nextDouble();
                while ((payment < TotalCost)||(payment > TotalCost)) {
                    System.out.println(payment + " is less or Greater than the required amount.");
                    System.out.println("Amount required is " + TotalCost + " KES");
                    System.out.print("Enter Valid Amount: ");
                    payment = cartype.nextDouble();
                }
                System.out.println("Payment made successfully..Thank you.");
                System.out.println("Wait for your Car to be deliver.");
            } else if (CarType == 7) {
                break; // back to main menu
            } else {
                System.out.println("Invalid Choice");
            }
        }
    }

    void ReturnCar() {
        while (true) {
            String[] id = {"44 DOT", "N22 VOL", "RJ12CB0012", "BO55 THZ", "J3IEPP", "TNCR7"};
            String[] make = {"Lamborghini", "Volkswagen", "Honda", "Mercedes Benz", "Jeep", "BMW"};
            String[] model = {"Huracan", "ID.Buzz", "HR-V", "GLC-Coupe", "Gladiator", "iX"};
            String[] Year = {"2021", "2023", "2019", "2020", "2017", "2018"};
            double[] cost = {3578.345, 5578.315, 1778.245, 2578.955, 3978.542, 4578.985};

            System.out.print("Enter the Car name (or type 'exit' to go back): ");
            cartype.nextLine(); //create the newline
            carname = cartype.nextLine();

            if (carname.equalsIgnoreCase("exit")) {
                break; // back to main menu
            }

            boolean found = false;
            for (int i = 0; i < make.length; i++) {
                if (carname.equalsIgnoreCase(make[i])) {
                    System.out.println("Car summary Details are:");
                    System.out.println("\n SUMMARY\n");
                    System.out.println("Car ID Number: " + id[i]);
                    System.out.println("Car make: " + make[i]);
                    System.out.println("Car model: " + model[i]);
                    System.out.println("Car Year: " + Year[i]);
                    System.out.println("Cost per/hour: " + cost[i] + " KES");
                    System.out.println(carname + " return Successful..Thank you.");
                    found = true;
                    break;
                }
            }

            if (!found) {
                System.out.println("Invalid car name. Please try again.");
            }
        }
    }
}

class Customer {
    private int IdNo;
    private String name;
    private String email;
    private int phone;
    private String CarType;
    Scanner detail = new Scanner(System.in);

    void customerManagement() {
        while (true) {
            System.out.println("...Welcome to customer registration zone...");
            System.out.print("Enter your name (or type 'exit' to go back): ");
            name = detail.nextLine();
            if (name.equalsIgnoreCase("exit")) {
                break; // back to main menu
            }
            System.out.print("Enter your ID number: ");
            IdNo = detail.nextInt();
            detail.nextLine(); // consume newline
            System.out.print("Enter your email Address: ");
            email = detail.nextLine();
            System.out.print("Enter your phone number: ");
            phone = detail.nextInt();
            detail.nextLine(); // consume newline
            System.out.print("Enter the Car type you have Select: ");
            CarType = detail.nextLine();
            System.out.println("...Personal Detail Summary...");
            System.out.println("Name: " + name);
            System.out.println("ID no: " + IdNo);
            System.out.println("Email Address: " + email);
            System.out.println("Phone number: " + phone);
            System.out.println("Favourite Car Type: " + CarType);
            System.out.println("Detail Save Successfully");
            System.out.println("Please go back to menu and select car Renting to complete renting process.");
        }
    }
}

class RentalAgency {
    void Agency() {
        Scanner kol = new Scanner(System.in);
        while (true) {
            String[] id = {"44 DOT", "N22 VOL", "RJ12CB0012", "BO55 THZ", "J3IEPP", "TNCR7"};
            String[] make = {"Lamborghini", "Volkswagen", "Honda", "Mercedes Benz", "Jeep", "BMW"};
            String[] model = {"Huracan", "ID.Buzz", "HR-V", "GLC-Coupe", "Gladiator", "iX"};
            String[] Year = {"2021", "2023", "2019", "2020", "2017", "2018"};
            double[] cost = {3578.345, 5578.315, 1778.245, 2578.955, 3978.542, 4578.985};

            System.out.println("...Available Car make for rent information...");
            System.out.println("1) Lamborghini");
            System.out.println("2) Volkswagen");
            System.out.println("3) Honda");
            System.out.println("4) Mercedes Benz");
            System.out.println("5) Jeep");
            System.out.println("6) BMW");
            System.out.println("7) Back to Main Menu");
            System.out.print("Enter Choice: ");
            int choice = kol.nextInt();

            if (choice == 7) {
                break; // back to main menu
            }

            if (choice >= 1 && choice <= 6) {
                System.out.println("...Summary Details are...");
                System.out.println("Car ID Number: " + id[choice - 1]);
                System.out.println("Car make: " + make[choice - 1]);
                System.out.println("Car model: " + model[choice - 1]);
                System.out.println("Car Year: " + Year[choice - 1]);
                System.out.println("Rent Cost per hour: " + cost[choice - 1] + "/=");
                System.out.println("Back to main menu and select Customer information for registrstion.");
            } else {
                System.out.println("Sorry, there is no other car make type available for now.");
            }
        }
    }
}


public class CarRentalSystem {
	public static void main(String[] args)
	{
		 Car mycar = new Car();
	        RentalAgency agency = new RentalAgency();
	        Customer custo = new Customer();
	        Scanner col = new Scanner(System.in);
	        
	        while (true) {
	            System.out.println("\n...WELCOME TO CAR RENTAL SYSTEM ZONE...");
	            System.out.println("Services...Offer...");
	            System.out.println("1) Rental Agency");
	            System.out.println("2) Customer Infomation");
	            System.out.println("3) Car Renting\"");
	            System.out.println("4) Exit");
	            System.out.print("Please Enter Choice: ");
	            int choice = col.nextInt();

	            if (choice == 1)
	            {
	            	 agency.Agency();
	            }	
	            else if (choice == 2) 
	            {
	            	 custo.customerManagement();
	            }
	            else if (choice == 3) 
	            {
	               mycar.carRental();
	            } 
	            else if (choice == 4)
	            {
	                System.out.println("Exiting... Thank you for using the Car Rental System.");
	                break; // exit the program
	            } 
	            else {
	                System.out.println("Invalid choice, please try again.");}
	            
	        }
	    }
	}


	
		