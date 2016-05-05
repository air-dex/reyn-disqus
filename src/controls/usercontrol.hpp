#ifndef USERCONTROL_HPP
#define USERCONTROL_HPP

#include <QObject>
#include "../model/disqususer.hpp"
#include "../connection/disqusapi.hpp"

class UserControl : public QObject
{
	Q_OBJECT

	public:
		UserControl();
		static void declareQML();

	protected:
		DisqusAPI disqus;

		// Backend user
		Q_PROPERTY(DisqusUser * disqusUser READ getDisqusUser WRITE setDisqusUser NOTIFY disqusUserChanged)
		DisqusUser disqusUser;
		DisqusUser * getDisqusUser();
		void setDisqusUser(const DisqusUser & value);
		void setDisqusUser(const DisqusUser * value);

	signals:
		void disqusUserChanged();
};

#endif // USERCONTROL_HPP
