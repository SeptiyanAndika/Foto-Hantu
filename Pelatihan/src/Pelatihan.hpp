// Default empty project template
#ifndef Pelatihan_HPP_
#define Pelatihan_HPP_

#include <QObject>

namespace bb { namespace cascades { class Application; }}

/*!
 * @brief Application pane object
 *
 *Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class Pelatihan : public QObject
{
    Q_OBJECT
public:
    Pelatihan(bb::cascades::Application *app);
    virtual ~Pelatihan() {}
};


#endif /* Pelatihan_HPP_ */
