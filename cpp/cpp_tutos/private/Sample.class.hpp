/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smonte-e <smonte-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 09:03:55 by smonte-e          #+#    #+#             */
/*   Updated: 2024/04/04 10:55:07 by smonte-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_SAMPLE_H
# define SAMPLE_SAMPLE_H
#define RST "\033[0m"
#define RED "\033[1;31m"
#define GRN "\033[1;32m"
#define YEL "\033[1;33m"
#define BLU "\033[1;34m"
#define MAG "\033[1;35m"
#define CYA "\033[1;36m"
#define WHT "\033[1;37m"

class Sample
{
public:
	// Public members
	Sample();
	~Sample();
	
	int publicFoo;
	void publicBar(void) const;

private:
	// Private members
	int _privateFoo;
	void _privateBar(void) const;
};
#endif
