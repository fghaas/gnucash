Name: gnucash
Summary: GnuCash is an application to keep track of your finances.
Version: 1.3.4
Release: 1
Copyright: Free Software Foundation
Group: Applications/Finance
Source: http://www.gnucash.org/pub/gnucash/sources/stable/gnucash-%{PACKAGE_VERSION}.tar.gz
Packager: Dave Peticolas <peticola@cs.ucdavis.edu>
BuildRoot: /var/tmp/gnucash-%version
Requires: gnome-libs >= 1.0.40


%description
GnuCash is a personal finance manager. A check-book like
register GUI allows you to enter and track bank accounts,
stocks, income and even currency trades. The interface is
designed to be simple and easy to use, but is backed with
double-entry accounting principles to ensure balanced books.


%prep
%setup -q


%build
./configure --prefix=/usr --sysconfdir=/etc
make gnome


%install
rm -rf $RPM_BUILD_ROOT
make prefix=$RPM_BUILD_ROOT/usr sysconfdir=$RPM_BUILD_ROOT/etc install


%clean
rm -rf $RPM_BUILD_ROOT


%files
%defattr(444,root,root,755)
%attr(555,-,-) /usr/bin/gnucash.gnome
%attr(555,-,-) /usr/bin/gnc-prices
/usr/bin/gnucash
/usr/lib/gnucash
/usr/share/gnucash
/usr/share/gnome/apps/Applications/gnucash.desktop
/usr/share/locale/de/LC_MESSAGES/gnucash.mo
/usr/share/locale/en_GB/LC_MESSAGES/gnucash.mo
/usr/share/locale/fr/LC_MESSAGES/gnucash.mo
/usr/share/locale/sv/LC_MESSAGES/gnucash.mo
%config /usr/etc/gnucash
%doc /usr/doc/gnucash
%doc /usr/man/man1/gnucash.1
%doc /usr/man/man1/gnc-prices.1
