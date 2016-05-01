#ifndef APPLICATIONSETTINGS_HPP
#define APPLICATIONSETTINGS_HPP

#include "isettings.hpp"
#include "disqusapp.hpp"

class ApplicationSettings : public ISettings
{
	public:
		/// @fn ApplicationSettings();
		/// @brief Default constructor, with registered settings.
		ApplicationSettings();

		ApplicationSettings(DisqusApp app);

		void setDefault();
		bool isDefaultDisqusApp() const;

		virtual void sync();

		const DisqusApp getDisqusApp() const;

	protected:
		DisqusApp disqusApp;
};

#endif // APPLICATIONSETTINGS_HPP
