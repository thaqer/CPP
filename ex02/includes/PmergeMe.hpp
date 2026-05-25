/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 00:00:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2026/05/25 00:00:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <climits>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <list>
# include <sstream>
# include <stdexcept>
# include <string>
# include <vector>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void	run(int argc, char **argv);

private:
	typedef std::vector<int>	VectorInt;
	typedef std::list<int>	ListInt;

	void		validateArguments(int argc, char **argv) const;
	int			parsePositiveInt(const std::string &value) const;

	VectorInt	makeVector(int argc, char **argv) const;
	ListInt		makeList(int argc, char **argv) const;

	VectorInt	sortVector(const VectorInt &input) const;
	ListInt		sortList(const ListInt &input) const;

	std::vector<size_t>	makeJacobsthalOrder(size_t size) const;
	void				insertVector(VectorInt &chain, int value) const;
	void				insertList(ListInt &chain, int value) const;

	double		elapsedMicroseconds(clock_t start, clock_t end) const;
	void		printArguments(int argc, char **argv) const;
	void		printVector(const VectorInt &values) const;
};

#endif
