#pragma once

#include "tgbot/types/BotCommandScope.h"

#include <memory>


namespace TgBot {

/**
 * @brief Represents the scope of bot commands, covering all group and supergroup chats.
 *
 * @ingroup types
 */
    class BotCommandScopeAllGroupChats : public BotCommandScope {
    public:
        static const std::string TYPE;

        typedef std::shared_ptr<BotCommandScopeAllGroupChats> Ptr;

        BotCommandScopeAllGroupChats() {
            this->type = TYPE;
        }
    };
}