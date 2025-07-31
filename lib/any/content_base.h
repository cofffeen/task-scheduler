#pragma once

class ContentBase {
    public:
        virtual ContentBase* clone() = 0;
        virtual ~ContentBase() = default;
};
