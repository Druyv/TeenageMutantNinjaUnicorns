#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>

/// \class image_load_error
///
/// \brief image load error
///
/// This class is used to generate a image load error exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 19-1-2017
///
class image_load_error : public std::exception {
    public:
        /// \brief Constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The image name is also added to the string.
        ///
        /// \param[in] image_name The name of the image
        ///
        image_load_error(const std::string & image_name) :
            msg{ std::string{ "Can not load image with name: " } + image_name }
        {}

        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};
    
/// \class invalid_position
///
/// \brief Invalid position exception
///
/// This class can be used to generate a exception
/// when a incorrect position has been received using
/// input from a file.
///
/// \date 23-1-2017
///
class invalid_position : public std::exception {
    public:
        /// \brief Constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The character the invalid position was on can
        /// also be specified.
        ///
        /// \param[in] c The character the error occured on
        ///
        invalid_position(const char c) :
            msg{ std::string{ "Invalid position: " } + c }
        {}
        
        /// \brief constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable.
        ///
        invalid_position() :
            msg{ "Invalid position" }
        {}
            
        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};

/// \class end_of_file
///
/// \brief End of file error
///
/// This class is used to generate a end of file exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 26-1-2017
///
class end_of_file : public std::exception {
    public:
        /// \brief Default constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable.
        ///
        end_of_file() :
            msg{ std::string{ "Finished reading items from file" } }
        {}
            
        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};

/// \class unknown_color
///
/// \brief Unknown color error
///
/// This class is used to generate a unknown color exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 26-1-2017
///
class unknown_color : public std::exception {
    public:
        /// \brief Constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The color is also added to the string.
        ///
        /// \param[in] color The name of the color
        ///
        unknown_color(const std::string color) :
            msg{ std::string{ "Unknown color: " } + color }
        {}
            
        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};

/// \class unknown_type
///
/// \brief Unknown type error
///
/// This class is used to generate a unknown type error exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 24-1-2017
///
class unknown_type : public std::exception {
    public:
        /// \brief constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The type is also added to the string.
        ///
        /// \param[in] type The incorrect type that was received
        ///
        unknown_type(const std::string type) :
            msg{ "Unknown type: " + type}
        {}
            
        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};

/// \class audio_load_error
///
/// \brief audio_load_error
///
/// This class is used to generate a audio load error exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 24-1-2017
///
class audio_load_error : public std::exception {
    public:
	/// \brief constructor
	///
	/// This constructor puts a message into a string and saves that as
	/// a private variable. The audio name is also added to the string.
	///
	/// \param[in] load_name The name of the image
        ///
	audio_load_error(const std::string & audio_name) :
		msg{ std::string{ "Can not load audio with name: " } +audio_name }
	{}

	/// \brief return message
	///
	/// This function returns the message so it can be printed.
	/// It overrides the what function from the std::exception
	/// superclass, making it easy to capture. 
	/// 
	/// \retval const char * {The error message as a const char *}
        ///
	const char * what() const noexcept override {
		return msg.c_str();
	}
    private:
	std::string msg;
};


/// \class sheet_load_error
///
/// \brief sheet load error
///
/// This class is used to generate a sheet load error exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// 
class sheet_load_error : public std::exception {
public:
	/// \brief constructor
	///
	/// This constructor puts a message into a string and saves that as
	/// a private variable. The image name is also added to the string.
	///
	/// \param[in] image_name The name of the image
	sheet_load_error(const std::string & image_name) :
		msg{ std::string{ "Can not load sheet with name: " } +image_name }
	{}
	/// \brief return message
	///
	/// This function returns the message so it can be printed.
	/// It overrides the what function from the std::exception
	/// superclass, making it easy to capture. 
	/// 
	/// \retval const char * {The error message as a const char *}
	const char * what() const noexcept override {
		return msg.c_str();
	}
private:
	std::string msg;
};

/// \class font_load_error
///
/// \brief Can not load font
///
/// This class is used to generate a ufont load exception.
/// It inherrits the std::exception class so it can be easily caught
/// with an try catch block.
///
/// \date 31-1-2017
///
class font_load_error : public std::exception {
    public:
        /// \brief Constructor
        ///
        /// This constructor puts a message into a string and saves that as
        /// a private variable. The font name is also added to the string.
        ///
        /// \param[in] font The name of the font
        ///
        font_load_error(const std::string font) :
            msg{ std::string{ "Unknown font: " } + font }
        {}
            
        /// \brief Return message
        ///
        /// This function returns the message so it can be printed.
        /// It overrides the what function from the std::exception
        /// superclass, making it easy to capture. 
        /// 
        /// \retval const char * {The error message as a const char *}
        ///
        const char * what() const noexcept override{
            return msg.c_str();
        }
    private:
        std::string msg;
};

#endif // EXCEPTIONS_HPP
