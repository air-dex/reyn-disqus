# C++ sources

SOURCES += \
	src/constants.cpp \
	src/utils.cpp \
	src/connection/networkresponse.cpp \
	src/connection/communicator.cpp \
	src/connection/communicatormanager.cpp \
	src/connection/authenticator.cpp \
	src/connection/genericrequester.cpp \
	src/connection/authrequester.cpp \
	src/connection/requests/oauthaccessrequester.cpp \
	src/connection/requests/accesstokensrequester.cpp \
	src/connection/requests/refreshtokenrequester.cpp \
	src/connection/requestermanager.cpp \
	src/connection/disqusapi.cpp \
	src/model/settings/disqusscopes.cpp \
	src/model/settings/disqusscopesset.cpp \
	src/model/settings/disqusapp.cpp \
	src/model/settings/usertokens.cpp \
	src/model/settings/usersettings.cpp \
	src/model/settings/applicationsettings.cpp \
	src/model/settings/rdsettings.cpp \
	src/controls/settingscontrol.cpp \
	src/controls/authcontrol.cpp \
	src/global.cpp \
	src/main.cpp

HEADERS += \
	src/constants.hpp \
	src/utils.hpp \
	src/connection/httprequesttype.hpp \
	src/connection/httpmaps.hpp \
	src/connection/httpcode.hpp \
	src/connection/networkresulttype.hpp \
	src/connection/networkresponse.hpp \
	src/connection/communicator.hpp \
	src/connection/communicatormanager.hpp \
	src/connection/responseinfos.hpp \
	src/connection/requestinfos.hpp \
	src/connection/requestresult.hpp \
	src/connection/authenticator.hpp \
	src/connection/genericrequester.hpp \
	src/connection/requests/oauthaccessrequester.hpp \
	src/connection/requests/accesstokensrequester.hpp \
	src/connection/requests/refreshtokenrequester.hpp \
	src/connection/authrequester.hpp \
	src/connection/requests/alldisqusrequesters.hpp \
	src/connection/requestermanager.hpp \
	src/connection/disqusapi.hpp \
	src/model/settings/disqusscopes.hpp \
	src/model/settings/disqusscopesset.hpp \
	src/model/settings/disqusapp.hpp \
	src/model/settings/isettings.hpp \
	src/model/settings/usertokens.hpp \
	src/model/settings/usersettings.hpp \
	src/model/settings/applicationsettings.hpp \
	src/model/settings/rdsettings.hpp \
	src/controls/settingscontrol.hpp \
	src/controls/authcontrol.hpp \
	src/global.hpp
