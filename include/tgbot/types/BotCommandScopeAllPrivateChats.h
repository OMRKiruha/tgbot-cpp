#pragma once

#include "tgbot/types/BotCommandScope.h"

#include <memory>


namespace TgBot {

/**
 * @brief Represents the scope of bot commands, covering all private chats.
 *
 * @ingroup types
 */
    class BotCommandScopeAllPrivateChats : public BotCommandScope {
    public:
        static const std::string TYPE;

        typedef std::shared_ptr<BotCommandScopeAllPrivateChats> Ptr;

        BotCommandScopeAllPrivateChats() {
            this->type = TYPE;
        }
    };
}
