<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', getenv('DB_NAME') );

/** Database username */
define( 'DB_USER', getenv('DB_USER') );

/** Database password */
define( 'DB_PASSWORD', getenv('DB_PASSWORD') );

/** Database hostname */
define( 'DB_HOST', getenv('DB_HOST') );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define( 'WP_ALLOW_REPAIR', true );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
	define('AUTH_KEY',         'Iayi41Eqjl{%C|v%Rnu>:-}<kYzRSWEf,*MPDzZB;amwaB&U{IWG@PrT3^#Ur4>=');
	define('SECURE_AUTH_KEY',  'H?#uBMSRcWx<l;~xWl-CmOc.2j|s/ldF`6rrq6$.ennfTY+w!::D4SQ#J9k-5St?');
	define('LOGGED_IN_KEY',    '/vrFGQ~(EFxD`>G@n(}`&^&u9KL[-M`$Eaj[s;VL *rC-BsCkGkQ(k>jW:G.W{(}');
	define('NONCE_KEY',        ';GQ=1X%3E)$yymfv+4}Bb_2ty@;|&go>TwRC`~T8D{-5J}8$*8F<mpbp`bo^QW05');
	define('AUTH_SALT',        'j+[dBP]7igR,0 aF9|f|?EbJw/Z;%,8xlVQqi-z|&uNOM9=qPSX(xp ~yKV.A5O-');
	define('SECURE_AUTH_SALT', 'E?I0L/yQH^[]|hD)&6*3uR>s#7r]F9iZJE8eevM*,iV`@r#uF~z<FgVf1LP8B>JE');
	define('LOGGED_IN_SALT',   ';i:N5-^yc0h?/1_wGZ#d-?k0|`P;Yi+QQeq?8a33iT#,<,xe*XdIDX;%=+i heVX');
	define('NONCE_SALT',       'UKY+-0-qm(kU+{&/3XlO},B^}apxvs~K}t<eIb0Y)nKhyh=a4Y``dka?oSq{x^Xl');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */


/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', '/var/www/html/wordpress' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';