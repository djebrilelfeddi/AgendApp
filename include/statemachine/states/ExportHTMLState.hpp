#ifndef EXPORTHTMLSTATE_HPP
#define EXPORTHTMLSTATE_HPP

#include "../BaseState.hpp"
#include <memory>

class ExportHTMLState final : public BaseState {
public:
    std::unique_ptr<BaseState> handle(StateMachine&) override;
};

#endif
