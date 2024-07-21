#include <iostream>

class Warlock
{
	private:
		std::string _name;
		std::string _title;

		Warlock();	//NOTE: 3 private, 2 public
		Warlock(Warlock const & src);
		Warlock &operator=(Warlock const & src);

	public:
		std::string const & getName() const; //NOTE: const ... const
		std::string const & getTitle() const;

		void setTitle(std::string const & str); //NOTE: ... xx(const) ...
		Warlock(std::string _name, std::string _title);
		~Warlock();
		void introduce() const; //NOTE: void introduce() const
};