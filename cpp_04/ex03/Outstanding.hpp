#ifndef OUTSTANDING_H
# define OUTSTANDING_H

/* ===== PRINT ALL LOGS ===== */
# define VERBOSE 0

/* === COLORS === */
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define ORANGE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define BLUE "\x1B[36m"
# define LIGHTGREY "\x1B[37m"
# define BROWN "\x1B[33m"
# define END "\033[0m"

/* ===== MACROS ===== */
# define MAC_CONSTRUCT "🔨" //LIGHTGREY
# define MAC_DESTRUCT "🗑" //RED
# define MAC_COPY "💾" //LIGHTGREY
# define MAC_CURE "💊" //GREEN
# define MAC_ICE "⛄️" //BLUE
# define MAC_LEARN "🎓" //PURPLE
# define MAC_EQUIP "📥" //ORANGE
# define MAC_DROP "🤚🏼" //ORANGE
# define MAC_CANT "❌" //BROWN
# define MAC_NOTHING "😴" //BROWN
# define MAC_INVENTORY "🎒" //ORANGE
# define MAC_EMPTY " "

#endif