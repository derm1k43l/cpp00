/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:25:37 by mrusu             #+#    #+#             */
/*   Updated: 2024/09/04 15:38:17 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook() : currentIndex_(0) 
{
}

// Destructor
PhoneBook::~PhoneBook() 
{
}

// Add a contact to the phonebook
void PhoneBook::addContact()
{
	Contact newContact;
	std::string input;

	std::cout << "Enter First Name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Field can not be empty." << std::endl;
		return ;
	}
	newContact.setFirstName(input);

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Field can not be empty." << std::endl;
		return ;
	}
	newContact.setLastName(input);

	std::cout << "Enter Nickname: ";
	std::getline(std::cin, input);
		if (input.empty())
	{
		std::cout << "Field can not be empty." << std::endl;
		return ;
	}
	newContact.setNickname(input);

	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);

	std::cout << "Enter Darkest Secret: ";
	std::getline(std::cin, input);
	newContact.setDarkestSecret(input);
	
	contacts_[currentIndex_] = newContact;
	currentIndex_ = (currentIndex_ + 1) % 8;
}

// Search for a contact in the phonebook
void PhoneBook::searchContact() const
{
	std::cout << "|Index     |First Name|Last Name |Nickname  |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		if(!contacts_[i].getFirstName().empty())
		{
			std::cout << "|" << std::setw(10) << (i + 1)
					<< "|" << std::setw(10) << truncateString(contacts_[i].getFirstName(), 10)
					<< "|" << std::setw(10) << truncateString(contacts_[i].getLastName(), 10)
					<< "|" << std::setw(10) << truncateString(contacts_[i].getNickname(), 10)
					<< "|" << std::endl;
		}
	}

	int index;
	std::string input;
	
	std::cout << "Enter the index of the contact you want to view in detail: ";
	std::getline(std::cin, input);
	
	if (input.empty() || !std::isdigit(input[0]) || (index = std::stoi(input)) < 1 || index > 8)
	{
		std::cout << "Invalid index!" << std::endl;
		return ;
	}

	if (index >= 1 && index <= 8 && !contacts_[index - 1].getFirstName().empty())
	{
		std::cout << "First Name: " << contacts_[index - 1].getFirstName() << std::endl;
		std::cout << "Last Name: " << contacts_[index - 1].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts_[index - 1].getNickname() << std::endl;
		std::cout << "Phone Number: " << contacts_[index - 1].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts_[index - 1].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index!" << std::endl;
}


std::string PhoneBook::truncateString(const std::string& str, size_t width) const
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	else
		return (str);
}

std::string PhoneBook::getDetails(const std::string &str)
{
	std::string input;
	std::cout << str;
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Field can not be empty. " << str;
		std::getline(std::cin, input);
	}
	return (input);
}
