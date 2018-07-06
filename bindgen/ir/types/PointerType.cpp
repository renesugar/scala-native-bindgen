#include "PointerType.h"
#include "../../Utils.h"

PointerType::PointerType(std::shared_ptr<Type> type) : type(std::move(type)) {}

std::string PointerType::str() const {
    return "native.Ptr[" + type->str() + "]";
}

bool PointerType::usesType(const std::shared_ptr<Type> &type) const {
    return *this->type == *type;
}

bool PointerType::operator==(const Type &other) const {
    if (this == &other) {
        return true;
    }
    if (isInstanceOf<const PointerType>(&other)) {
        auto *pointerType = dynamic_cast<const PointerType *>(&other);
        return *type == *pointerType->type;
    }
    return false;
}
