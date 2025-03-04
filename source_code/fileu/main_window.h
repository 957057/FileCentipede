#ifndef PRO_MAIN_WINDOW_H
#define PRO_MAIN_WINDOW_H

#include "pro_global.h"
#include "pro_sample.h"
#include "tasks/tasks_main.h"
#include "tasks/tasks_confirm_links.h"
#include "local_files/local_files_main.h"
#include "search_engine/search_engine_main.h"
#include "view/view_statistics.h"
#include "view/view_desktop_shortcuts.h"
#include "tools/tool_http.h"
#include "tools/tool_create_torrent.h"
#include "tools/tool_create_address.h"
#include "tools/tool_file_merge.h"
#include "tools/tool_software_release.h"
#include "settings/settings_main.h"
#include "settings/settings_speed_limit.h"
#include "settings/settings_proxies.h"
#include "settings/settings_trackers.h"
#include "settings/settings_filter.h"
#include "settings/settings_torrent_query.h"
#include "help/help_update.h"
#include "help/help_install.h"
#include "help/help_uninstall.h"
#include "help/help_translator.h"

namespace pro
{

class main_window
{
public:
    main_window(ext::ui::application& app);


public:
    ~main_window();


public:
    /*
     * global
    */
    pro::global zzz;


protected:
    /*
     * sml
    */
    ext::ui::context sml_;
    /*
     * ui
    */
    ext::ui::model ui;
    /*
     * window
    */
    ext::ui::window* window_ = nullptr;
    /*
     * status
    */
    ext::ui::form status_form_;


protected:
    /*
     * actions initialized
    */
    ext::boolean_t actions_initialized_ = false;
    /*
     * tray initialized
    */
    ext::boolean_t tray_initialized_ = false;
    /*
     * clipboard initialized
    */
    ext::boolean_t clipboard_initialized_ = false;
    /*
     * window size changed
    */
    ext::boolean_t window_size_changed_ = false;
    /*
     * timer
    */
    std::int64_t timer_ = 0;
    /*
     * timepoint interval
    */
    ext::steady_time_point_t timepoint_interval_;
    /*
     * timepoint interval second
    */
    ext::steady_time_point_t timepoint_interval_second_;
    /*
     * interval handlers
    */
    std::unordered_map<ext::text,ext::value_view> interval_handlers_;
    /*
     * queued messages
    */
    std::vector<ext::value> queued_messages_;


protected:
    /*
     * tasks
    */
    pro::tasks::main tasks_;
    /*
     * search engine
    */
    pro::search_engine::main* search_engine_ = nullptr;
    /*
     * statistics
    */
    pro::view::statistics* view_statistics_ = nullptr;


protected:
    /*
     * settings
    */
    pro::settings::main* settings_ = nullptr;
    /*
     * proxies
    */
    pro::settings::proxies* proxies_ = nullptr;
    /*
     * trackers
    */
    pro::settings::trackers* trackers_ = nullptr;
    /*
     * filter
    */
    pro::settings::filter* filter_ = nullptr;
    /*
     * torrent query
    */
    pro::settings::torrent_query* torrent_query_ = nullptr;
    /*
     * update
    */
    pro::help::update* help_update_ = nullptr;


protected:
    /*
     * init ui
    */
    void init_ui();
    /*
     * init config
    */
    void init_config();
    /*
     * init views
    */
    void init_views();
    /*
     * init sizes
    */
    void init_sizes(ext::ui::object& object);
    /*
     * init events
    */
    void init_events();
    /*
     * init actions
    */
    void init_actions();
    /*
     * init ipc
    */
    void init_ipc();
    /*
     * init tabs
    */
    void init_tabs();
    /*
     * init tray
    */
    void init_tray();
    /*
     * init clipboard
    */
    void init_clipboard();
    /*
     * init methods
    */
    void init_methods();
    /*
     * init timer
    */
    void init_timer();
    /*
     * init plugins
    */
    void init_plugins();


protected:
    /*
     * launch filec
    */
    void launch_filec();
    /*
     * show ipc loading
    */
    void show_ipc_loading();
    /*
     * connect service
    */
    void connect_service();


protected:
    /*
     * on timer
    */
    void on_timer();
    /*
     * on timer 200ms
    */
    void on_timer_200ms(ext::steady_time_t now);
    /*
     * on timer 1s
    */
    void on_timer_1s(ext::steady_time_t now);


protected:
    /*
     * on version
    */
    void on_version(ext::value& json);
    /*
     * on stop
    */
    void on_stop();
    /*
     * on service close
    */
    void on_service_close();
    /*
     * on service connected
    */
    void on_service_connected(std::shared_ptr<ext::ipcx::connection>& connection);
    /*
     * on subscribe add
    */
    void on_subscribe_add(ext::value& json);
    /*
     * on subscribe update
    */
    void on_subscribe_update(ext::value& json);
    /*
     * on subscribe remove
    */
    void on_subscribe_remove(ext::value& json);
    /*
     * on error
    */
    void on_error(ext::value& json);
    /*
     * on client message
    */
    void on_client_message(ext::value& json);
    /*
     * on xmessage
    */
    void on_xmessage(uint16_t at,ext::value& json);
    /*
     * on message2
    */
    void on_message2(uint16_t at,ext::value& json);
    /*
     * on message
    */
    void on_message(uint16_t at,ext::value& json);
    /*
     * on message
    */
    void on_message(uint8_t* data,uint32_t length);
    /*
     * on client
    */
    void on_client(std::shared_ptr<ext::ipcx::client> client);
    /*
     * on status
    */
    void on_status(ext::value& json);
    /*
     * on trackers
    */
    void on_trackers(ext::value& json);


public:
    /*
     * add task
    */
    void add_task(ext::text_view uri,bool important = false);
    /*
     * open files
    */
    void open_files();


public:
    /*
     * create
    */
    void create();

};

}




#endif
