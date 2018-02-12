#ifndef APPROVALS_H
#define APPROVALS_H

#include <string>
#include <functional>
#include "FileApprover.h"
#include "reporters/DiffReporter.h"
#include "reporters/Reporter.h"
#include "namers/ApprovalNamer.h"

class Approvals
{
private:
    Approvals() {}
    ~Approvals() {}
public:
    static void verify( std::string contents,const Reporter& reporter = DiffReporter() )
    {
        StringWriter writer( contents );
        ApprovalNamer namer;
        FileApprover::verify(namer, writer, reporter);
    }

    template <typename T>
    static void verify(T contents, const Reporter& reporter = DiffReporter())
    {
        std::stringstream s;
        s << contents;
        verify(s.str(), reporter);
    }

    template <typename T>
    static void verifyAll(std::string header,
                          const std::vector<T>& list,
                          std::function<void (T, std::ostream&)> converter,
                          const Reporter& reporter = DiffReporter())
    {
        std::stringstream s;
        if( !header.empty())
        {
            s << header << "\n\n\n";
        }
        for( const auto& element : list)
        {
            converter(element, s);
            s << '\n';
        }
        verify(s.str(), reporter);
    }

    template <typename T>
    static void verifyAll(std::string header,
                          const std::vector<T>& list,
                          const Reporter& reporter = DiffReporter())
    {
        int i = 0;
        verifyAll<T>(header, list, [&](T element, std::ostream& s){s << "[" << i++ << "] = " << element;}, reporter);
    }

    template <typename T>
    static void verifyAll(const std::vector<T>& list,
                          const Reporter& reporter = DiffReporter())
    {
        verifyAll<T>("", list, reporter);
    }
};

#endif