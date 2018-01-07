%define debug_package %{nil}

Summary: Open X Input Method Setup.
Name: oxim-setup-gtk
Version: 1.1.6
Release: 1
License: GPL
Group: System/Internationalization
Source0: %{name}-%{version}.tar.gz
Requires: zlib
Requires: %{name} = %{version}
Requires: gtk2

Requires(post,preun): /usr/sbin/alternatives
BuildRequires: zlib-devel
BuildRequires: gtk2-devel
Buildroot: %{_tmppath}/%{name}-buildroot

%description
An X Input Method Setup.



%prep

rm -rf $RPM_BUILD_ROOT
%setup -q

%build
make

%install


rm -rf $RPM_BUILD_ROOT
DESTDIR=$RPM_BUILD_ROOT make install





%clean 
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%{_bindir}/%{name}
%{_datadir}/%{name}/oxim-setup-glade.glade
%{_datadir}/%{name}/gtkrc
#%{_datadir}/applications/oxim-setup.desktop
#%{_datadir}/pixmaps/oxim-setup.png


%changelog
* Fri Aug 15 2008 milochen <milo_chen@mail2000.com.tw>
- Initial package
* Sun Jan 01 2018 milochen <milo@pieapple.com>
- Source Code Transfer
