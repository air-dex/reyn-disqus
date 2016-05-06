#ifndef USERCONTROL_HPP
#define USERCONTROL_HPP

#include <QObject>
#include "../model/disqususer.hpp"
#include "../connection/disqusapi.hpp"
#include "../connection/requestresult.hpp"

class UserControl : public QObject
{
	Q_OBJECT

	public:
		UserControl();
		static void declareQML();
		Q_INVOKABLE void loadUserDetails(int userID);

	protected slots:
		void userDetailsLoaded(RequestResult reqres);

	protected:
		DisqusAPI disqus;

		// Backend user
		Q_PROPERTY(DisqusUser * disqusUser READ getDisqusUser WRITE setDisqusUser NOTIFY disqusUserChanged)
		DisqusUser disqusUser;
		DisqusUser * getDisqusUser();
		void setDisqusUser(const DisqusUser & value);
		void setDisqusUser(const DisqusUser * value);
		void setDisqusUser(const QJsonObject & value);

	signals:
		void disqusUserChanged();
		void fatalError(QString error);
		void needRefresh();
		void loadUsersDetailsFailed(QString infos);
};

#endif // USERCONTROL_HPP
