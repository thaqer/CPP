/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/05/25 12:29:43 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return (*this);
}
PmergeMe::~PmergeMe() {}

void	PmergeMe::run(int argc, char **argv)
{
	VectorInt	vectorResult;
	ListInt		listResult;
	clock_t		start;
	clock_t		end;
	double		vectorTime;
	double		listTime;

	validateArguments(argc, argv);
	std::cout << "Before: ";
	printArguments(argc, argv);

	start = clock();
	vectorResult = sortVector(makeVector(argc, argv));
	end = clock();
	vectorTime = elapsedMicroseconds(start, end);

	start = clock();
	listResult = sortList(makeList(argc, argv));
	end = clock();
	listTime = elapsedMicroseconds(start, end);

	(void)listResult;
	std::cout << "After: ";
	printVector(vectorResult);
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << vectorResult.size()
		<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << vectorResult.size()
		<< " elements with std::list : " << listTime << " us" << std::endl;
}

void	PmergeMe::validateArguments(int argc, char **argv) const
{
	if (argc < 2)
		throw std::invalid_argument("missing argument");
	for (int i = 1; i < argc; ++i)
		parsePositiveInt(argv[i]);
}

int	PmergeMe::parsePositiveInt(const std::string &value) const
{
	std::istringstream	stream(value);
	long				number;
	char				extra;

	if (value.empty())
		throw std::invalid_argument("empty argument");
	for (size_t i = 0; i < value.length(); ++i)
	{
		if (value[i] < '0' || value[i] > '9')
			throw std::invalid_argument("invalid character");
	}
	if (!(stream >> number) || (stream >> extra)
		|| number <= 0 || number > INT_MAX)
		throw std::invalid_argument("invalid number");
	return (static_cast<int>(number));
}

PmergeMe::VectorInt	PmergeMe::makeVector(int argc, char **argv) const
{
	VectorInt	values;

	values.reserve(argc - 1);
	for (int i = 1; i < argc; ++i)
		values.push_back(parsePositiveInt(argv[i]));
	return (values);
}

PmergeMe::ListInt	PmergeMe::makeList(int argc, char **argv) const
{
	ListInt	values;

	for (int i = 1; i < argc; ++i)
		values.push_back(parsePositiveInt(argv[i]));
	return (values);
}

PmergeMe::VectorInt	PmergeMe::sortVector(const VectorInt &input) const
{
	VectorInt			mainChain;
	VectorInt			pending;
	std::vector<size_t>	order;

	if (input.size() <= 1)
		return (input);
	mainChain.reserve((input.size() + 1) / 2);
	pending.reserve(input.size() / 2 + 1);
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			pending.push_back(input[i]);
			mainChain.push_back(input[i + 1]);
		}
		else
		{
			pending.push_back(input[i + 1]);
			mainChain.push_back(input[i]);
		}
	}
	if (input.size() % 2)
		pending.push_back(input.back());
	mainChain = sortVector(mainChain);
	order = makeJacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
		insertVector(mainChain, pending[order[i]]);
	return (mainChain);
}

PmergeMe::ListInt	PmergeMe::sortList(const ListInt &input) const
{
	ListInt				mainChain;
	ListInt				pending;
	std::vector<size_t>	order;

	if (input.size() <= 1)
		return (input);
	for (ListInt::const_iterator it = input.begin(); it != input.end();)
	{
		int	first = *it++;
		if (it == input.end())
		{
			pending.push_back(first);
			break ;
		}
		int	second = *it++;
		if (first < second)
		{
			pending.push_back(first);
			mainChain.push_back(second);
		}
		else
		{
			pending.push_back(second);
			mainChain.push_back(first);
		}
	}
	mainChain = sortList(mainChain);
	order = makeJacobsthalOrder(pending.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		ListInt::const_iterator it = pending.begin();
		std::advance(it, order[i]);
		insertList(mainChain, *it);
	}
	return (mainChain);
}

std::vector<size_t>	PmergeMe::makeJacobsthalOrder(size_t size) const
{
	std::vector<size_t>	order;
	size_t				previous;
	size_t				jacobPrevious;
	size_t				jacob;

	if (size == 0)
		return (order);
	order.push_back(0);
	previous = 1;
	jacobPrevious = 1;
	jacob = 3;
	while (previous < size)
	{
		size_t	limit = jacob;

		if (limit > size)
			limit = size;
		for (size_t i = limit; i > previous; --i)
			order.push_back(i - 1);
		size_t next = jacob + 2 * jacobPrevious;
		jacobPrevious = jacob;
		jacob = next;
		previous = limit;
	}
	return (order);
}

void	PmergeMe::insertVector(VectorInt &chain, int value) const
{
	VectorInt::iterator	begin = chain.begin();
	VectorInt::iterator	end = chain.end();

	while (begin < end)
	{
		VectorInt::iterator middle = begin + (end - begin) / 2;

		if (*middle < value)
			begin = middle + 1;
		else
			end = middle;
	}
	chain.insert(begin, value);
}

void	PmergeMe::insertList(ListInt &chain, int value) const
{
	ListInt::iterator	it = chain.begin();

	while (it != chain.end() && *it < value)
		++it;
	chain.insert(it, value);
}

double	PmergeMe::elapsedMicroseconds(clock_t start, clock_t end) const
{
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

void	PmergeMe::printArguments(int argc, char **argv) const
{
	for (int i = 1; i < argc; ++i)
	{
		if (i > 1)
			std::cout << " ";
		std::cout << argv[i];
	}
	std::cout << std::endl;
}

void	PmergeMe::printVector(const VectorInt &values) const
{
	for (VectorInt::const_iterator it = values.begin(); it != values.end(); ++it)
	{
		if (it != values.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}
