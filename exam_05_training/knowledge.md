
- When const is at the end of the member function declaration, it means that the function does not modify the state of the object.
This means that none of the member variables can be changed within that function. These functions can be called on const objects.

	std::string const & getTitle() const;
	void introduce() const;

Here, getTitle and introduce promise not to modify any member variables of the Warlock object.

- When const is at the beginning of the function declaration (before the return type), it means the function returns a constant value.
This implies that the caller cannot modify the returned value directly.

	std::string const & getTitle() const;

In this case, getTitle returns a reference to a constant std::string, meaning the caller cannot modify the returned string directly.
This is important for protecting internal class data from being changed inadvertently.

- When const is used inside the parameter list, it means that the parameter is read-only within the function.
The function will not (and cannot) modify the value of this parameter. If the parameter is passed by reference, this can also help avoid unnecessary copying.

	void setTitle(std::string const & title);

Here, setTitle takes a constant reference to a std::string.
This means the function will not modify the input string title, and it also avoids copying the string, which is more efficient.


==> a la **FIN**:
	aucun des privates attributs de la classe ne peut etre changé dans la fonction  = peut etre *appelé sur des const objets*

==> au **DEBUT**:
	la fonction retourne une const value = le caller ne peut pas modifier la valeur de retour ( = sécurité pour éviter les erreurs)

==> dans les **pARAMETRES**:
	le paramètre est read-only dans la fonction = la fonction ne va/peut pas modifier la valeur du paramètre
