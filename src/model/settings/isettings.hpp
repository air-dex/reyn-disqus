#ifndef ISETTINGS_HPP
#define ISETTINGS_HPP

class QSettings;

/// @class ISettings
/// @brief Interface for classes handling settings.
class ISettings
{
	public:
		/// @fn virtual void sync() = 0;
		/// @brief Syncing settings
		virtual void sync() = 0;
};

#endif // ISETTINGS_HPP
