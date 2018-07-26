/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obaranni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 17:06:05 by obaranni          #+#    #+#             */
/*   Updated: 2018/07/17 18:27:11 by obaranni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
# include "capture.h"

int			main(void) {


	int				debug;
	t_cap_stdout	cap;
	char			*printf_out;
	int				printf_ret;
	char			*ft_printf_out;
	int				ft_printf_ret;



    int i = 0;
    char *s;
    setlocale(LC_CTYPE,"de_DE.UTF-8");

    while (i++ != 1) {
		capture_stdout();
		printf_ret = printf("%*d", 5, 42);
		printf_out = strdup(capture_stdout_get_buffer());
//
//
//
		ft_printf_ret = ft_printf("%*d", 5, 42);
		ft_printf_out = strdup(capture_stdout_get_buffer());
		capture_stdout_destroy();
		if (ft_strcmp(ft_printf_out, printf_out) != 0 || printf_ret != ft_printf_ret)
		{
			fprintf(stderr, "\nTEST not my\n");
			fprintf(stderr, "=====   printf_out  =====\nret: %d\n%s\n", printf_ret, printf_out);
			fprintf(stderr,   "=========================\n");

			fprintf(stderr, "\nTEST my my\n");
			fprintf(stderr, "=====   printf_out  =====\nret: %d\n%s\n", ft_printf_ret, ft_printf_out);
			fprintf(stderr,   "=========================\n");
		}


//		printf("40 Hello \"%s %C %d %p %x %% %S\"\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
//		ft_printf("40 Hello \"%s %C %d %p %x %% %S\"\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
//
//
//
//		printf("Returned: %d\n", printf("%1C", 200));
//		printf("Returned: %d\n\n", ft_printf("%1C", 200));
//
//		printf("Returned: %d\n", printf("%1C", 200));
//		printf("Returned: %d\n\n", ft_printf("%1C", 200));
//
//		printf("Returned: %d\n", printf("%c", 200));
//		printf("Returned: %d\n\n", ft_printf("%c", 200));
//
//		printf("Returned: %d\n", printf("%s\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*"));
//		printf("Returned: %d\n\n", ft_printf("%s\n", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*"));
//
//		printf("Returned: %d\n", printf("% d", 9999));
//		printf("Returned: %d\n\n", ft_printf("% d", 9999));
//
//		printf("Returned: %d\n", printf("%      i", 42));
//		printf("Returned: %d\n\n", ft_printf("%      i", 42));
//
//
//
//		printf("Returned: %d\n", printf("%D", LONG_MIN));
//		printf("Returned: %d\n\n", ft_printf("%D", LONG_MIN));
//
//		printf("Returned: %d\n", printf("%4.15d", -42));
//		printf("Returned: %d\n\n", ft_printf("%4.15d", -42));
////
//		printf("Returned: %d\n", printf("%- i", 42));
//		printf("Returned: %d\n\n", ft_printf("%- i", 42));
//
//		printf("Returned: %d\n", printf("% d", 42));
//		printf("Returned: %d\n\n", ft_printf("% d", 42));
//
//		printf("Returned: %d\n", printf("%03.2d", 0));
//		printf("Returned: %d\n\n", ft_printf("%03.2d", 0));
//
//
//		printf("Returned: %d\n\n", printf("1 Hello \"%hd\"\n", SHRT_MIN - SHRT_MIN));
//		printf("Returned: %d\n\n", ft_printf("1 Hello \"%hd\"\n", SHRT_MIN - SHRT_MIN));
//
//        printf("Returned: %d\n", printf("%4.10d\n", 89));
//        printf("Returned: %d\n\n", ft_printf("%4.10d\n", 89));
//
//        printf("Returned: %d\n", printf("2 Hello \"% 2.10d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("2 Hello \"% 2.10d\"\n", 89));
//
//        printf("Returned: %d\n", printf("2.1 Hello \"% d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("2.1 Hello \"% d\"\n", 89));
//
//		printf("% d\n", 42);
//		ft_printf("% d\n", 42);
//
//
//
//
//		printf("Returned: %d\n", printf("%+ d", 42));
//		printf("Returned: %d\n\n", ft_printf("%+ d", 42));
//
//		printf("Returned: %d\n", printf("%+ d", -42));
//		printf("Returned: %d\n\n", ft_printf("%+ d", -42));
//
//		printf("Returned: %d\n", printf("%- d", -42));
//		printf("Returned: %d\n\n", ft_printf("%- d", -42));
//
//		printf("Returned: %d\n", printf("@moulitest: %.d %.0d", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("@moulitest: %.d %.0d", 0, 0));
//
//		printf("Returned: %d\n", printf("@moulitest: %5.d %5.0d", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("@moulitest: %5.d %5.0d", 0, 0));
//
//		printf("Returned: %d\n", printf("%.2d", 4242));
//		printf("Returned: %d\n\n", ft_printf("%.2d", 4242));
//
//		printf("Returned: %d\n", printf("%15d", 42));
//		printf("Returned: %d\n\n", ft_printf("%15d", 42));
//
//		printf("Returned: %d\n", printf("%.15d", 42));
//		printf("Returned: %d\n\n", ft_printf("%.15d", 42));
//
//		printf("Returned: %d\n", printf("%4.15d", 42));
//		printf("Returned: %d\n\n", ft_printf("%4.15d", 42));
//
//        printf("Returned: %d\n", printf("3 Hello \"% -10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("3 Hello \"% -10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4 Hello \"% -10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("4 Hello \"% -10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4.1 Hello \"% -+10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("4.1 Hello \"% -+10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("4.2 Hello \"%8.7i\"\n", 80009));
//        printf("Returned: %d\n\n", ft_printf("4.2 Hello \"%8.7i\"\n", 80009));
//
//        printf("Returned: %d\n", printf("5 Hello \"% +-10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("5 Hello \"% +-10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("6 Hello \"%+-10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("6 Hello \"%+-10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("7 Hello \"%+10.7d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("7 Hello \"%+10.7d\"\n", 89));
//
//        printf("Returned: %d\n", printf("8 Hello \"% +10.7d\"\n", -89));
//        printf("Returned: %d\n\n", ft_printf("8 Hello \"% +10.7d\"\n", -89));
//
//        printf("Returned: %d\n", printf("9 Hello \"% 0+10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("9 Hello \"% 0+10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("9.1 Hello \"% 0+10d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("9.1 Hello \"% 0+10d\"\n", 89));
//
//        printf("Returned: %d\n", printf("10 Hello \"% +10.3d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("10 Hello \"% +10.3d\"\n", 89));
//
//        printf("Returned: %d\n", printf("11 Hello \"% -+10.7d\"\n", -89));
//        printf("Returned: %d\n\n", ft_printf("11 Hello \"% -+10.7d\"\n", -89));
//
//        printf("Returned: %d\n", printf("12 Hello \"% 0+11.1d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("12 Hello \"% 0+11.1d\"\n", 89));
//
//        printf("Returned: %d\n", printf("13 Hello \"% 0 9.1d\"\n", 89));
//        printf("Returned: %d\n\n", ft_printf("13 Hello \"% 0 9.1d\"\n", 89));
//
//        printf("Returned: %d\n", printf("14 Hello \"%- 50.33lld\"\n", LONG_LONG_MIN));
//        printf("Returned: %d\n\n", ft_printf("14 Hello \"%- 50.33lld\"\n", LONG_LONG_MIN));
//
//		printf("Returned: %d\n", printf("14.1 Hello \"%lld\"\n", LONG_MIN));
//		printf("Returned: %d\n\n", ft_printf("14.1 Hello \"%lld\"\n", LONG_MIN));
//
//        printf("Returned: %d\n", printf("15 Hello \"%lld\"\n", LONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("15 Hello \"%lld\"\n", LONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("15.1 Hello \"%hd\"\n", SHRT_MIN));
//        printf("Returned: %d\n\n", ft_printf("15.1 Hello \"%hd\"\n", SHRT_MIN));
//
//        printf("Returned: %d\n", printf("16 Hello \"%hd\"\n", SHRT_MAX));
//        printf("Returned: %d\n\n", ft_printf("16 Hello \"%hd\"\n", SHRT_MAX));
//
//        printf("Returned: %d\n", printf("17 Hello \"%hhd\"\n", CHAR_MIN));
//        printf("Returned: %d\n\n", ft_printf("17 Hello \"%hhd\"\n", CHAR_MIN));
//
//        printf("Returned: %d\n", printf("18 Hello \"%hhd\"\n", CHAR_MAX));
//        printf("Returned: %d\n\n", ft_printf("18 Hello \"%hhd\"\n", CHAR_MAX));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%li\"\n", LONG_MIN));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%li\"\n", LONG_MIN));
//
//
//		printf("Returned: %d\n", printf("18.2 Hello \"%lU, %lU\"\n", 0, USHRT_MAX));
//		printf("Returned: %d\n\n", ft_printf("18.2 Hello \"%lU, %lU\"\n", 0, USHRT_MAX));
//
//        printf("Returned: %d\n", printf("19 Hello \"%u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("19 Hello \"%u\"\n", -1));
//
//        printf("Returned: %d\n", printf("20 Hello \"% 9.7u\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("20 Hello \"% 9.7u\"\n", -4235));
//
//        printf("Returned: %d\n", printf("20.1 Hello \"% 9.7u\"\n", -4294967294));
//        printf("Returned: %d\n\n", ft_printf("20.1 Hello \"% 9.7u\"\n", -4294967294));
//
//        printf("Returned: %d\n", printf("20.2 Hello \"% 9.7u\"\n", -42));
//        printf("Returned: %d\n\n", ft_printf("20.2 Hello \"% 9.7u\"\n", -42));
//
//        printf("Returned: %d\n", printf("21 Hello \"% 9.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("21 Hello \"% 9.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("22 Hello \"% 11.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("22 Hello \"% 11.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("23 Hello \"% -13.7u\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("23 Hello \"% -13.7u\"\n", -1));
//
//        printf("Returned: %d\n", printf("24 Hello \"% -13.7u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("24 Hello \"% -13.7u\"\n", 1));
//
//        printf("Returned: %d\n", printf("25 Hello \"% 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("25 Hello \"% 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("26 Hello \"%- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("26 Hello \"%- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("27 Hello \"%0+- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("27 Hello \"%0+- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("28 Hello \"%0+- 4u\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("28 Hello \"%0+- 4u\"\n", 1));
//
//        printf("Returned: %d\n", printf("29 Hello \"%.5i\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("29 Hello \"%.5i\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30 Hello \"%%\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30 Hello \"%%\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.1 Hello \"%5m\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.1 Hello \"%5m\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.2 Hello \"%5%\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.2 Hello \"%5%\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.3 Hello \"%-05K\"\n", -4235));
//        printf("Returned: %d\n\n", ft_printf("30.3 Hello \"%-05K\"\n", -4235));
//
//        printf("Returned: %d\n", printf("30.4 Hello \"%%\"\n", 1));
//        printf("Returned: %d\n\n", ft_printf("30.4 Hello \"%%\"\n", 1));
//
//        printf("Returned: %d\n", printf("31 Hello \"%U\"\n", ULONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("31 Hello \"%U\"\n", ULONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("31.1 Hello \"%hhU\"\n", ULONG_LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("31.1 Hello \"%hhU\"\n", ULONG_LONG_MAX));
//
//        printf("Returned: %d\n", printf("31.2 Hello \"%U\"\n", -1));
//        printf("Returned: %d\n\n", ft_printf("31.2 Hello \"%U\"\n", -1));
//
//        printf("Returned: %d\n", printf("31.3 Hello \"%U\"\n", 42));
//        printf("Returned: %d\n\n", ft_printf("31.3 Hello \"%U\"\n", 42));
//
//        printf("Returned: %d\n", printf("32 Hello \"%D\"\n", 42));
//        printf("Returned: %d\n\n", ft_printf("32 Hello \"%D\"\n", 42));
//
//        printf("Returned: %d\n", printf("32.1 Hello \"%D\"\n", -1L));
//        printf("Returned: %d\n\n", ft_printf("32.1 Hello \"%D\"\n", -1L));
//
//        printf("Returned: %d\n", printf("32.2 Hello \"%D\"\n", LONG_MAX));
//        printf("Returned: %d\n\n", ft_printf("32.2 Hello \"%D\"\n", LONG_MAX));
//
//        printf("Returned: %d\n", printf("32.3 Hello \"%D\"\n", LONG_MIN));
//        printf("Returned: %d\n\n", ft_printf("32.3 Hello \"%D\"\n", LONG_MIN));
//
//
//
//
//
//        printf("Returned: %d\n", printf("32.4 Hello \"%s\"\n", "pidr"));
//        printf("Returned: %d\n\n", ft_printf("32.4 Hello \"%s\"\n", "pidr"));
//
//		printf("Returned: %d\n", printf("32.5 Hello NULL_STR \"%s\"\n", (char*)NULL));
//		printf("Returned: %d\n\n", ft_printf("32.5 Hello NULL_STR \"%s\"\n", (char*)NULL));
//
//        printf("Returned: %d\n", printf("33 % "));
//        printf("Returned: %d\n\n", ft_printf("33 % "));
//
//		printf("Returned: %d\n", printf("33.1 \"{%}\""));
//		printf("Returned: %d\n\n", ft_printf("33.1 \"{%}\""));
//
//		printf("Returned: %d\n", printf("33.2 \"{%{\""));
//		printf("Returned: %d\n\n", ft_printf("33.2 \"{%{\""));
//
//		printf("Returned: %d\n", printf("33.3 \"{%[[[\""));
//		printf("Returned: %d\n\n", ft_printf("33.3 \"{%[[[\""));
//
//		printf("Returned: %d\n", printf("33.4 \"{%///\""));
//		printf("Returned: %d\n\n", ft_printf("33.4 \"{%///\""));
//
//		printf("Returned: %d\n", printf("33.5 \"{%00\""));
//		printf("Returned: %d\n\n", ft_printf("33.5 \"{%00\""));
//
//		printf("Returned: %d\n", printf("34 Hello \"%p\"\n", &i));
//		printf("Returned: %d\n\n", ft_printf("34 Hello \"%p\"\n", &i));
//
//		printf("Returned: %d\n", printf("34.1 Hello \"%p\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("34.1 Hello \"%p\"\n", 0));
//
//		printf("Returned: %d\n", printf("34.2 Hello \"%5p\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("34.2 Hello \"%5p\"\n", 0));
//
//		printf("Returned: %d\n", printf("34.2 Hello \"%015p\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("34.2 Hello \"%015p\"\n", 0));
//
//		printf("Returned: %d\n", printf("35 Hello \"%X\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35 Hello \"%X\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.1 Hello \"%X\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.1 Hello \"%X\"\n", 0));
//
//		printf("Returned: %d\n", printf("35.2 Hello \"%X\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.2 Hello \"%X\"\n", 4294967296));
//
//		printf("Returned: %d\n", printf("35.3 Hello \"%lx\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.3 Hello \"%lx\"\n", 4294967296));
//
//		printf("Returned: %d\n", printf("35.4 Hello \"%.2x\"\n", 4296));
//		printf("Returned: %d\n\n", ft_printf("35.4 Hello \"%.2x\"\n", 4296));
//
//		printf("Returned: %d\n", printf("35.5 Hello \"%#x\"\n", 4296));
//		printf("Returned: %d\n\n", ft_printf("35.5 Hello \"%#x\"\n", 4296));
//
//		printf("Returned: %d\n", printf("35.6 Hello \"%#x\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.6 Hello \"%#x\"\n", 0));
//
//		printf("Returned: %d\n", printf("35.7 Hello \"%#X\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35.7 Hello \"%#X\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.8 Hello \"%#8x\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35.8 Hello \"%#8x\"\n", 42));
//
//		printf("Returned: %d\n", printf("35.9 Hello \"%#.x %#.0x\"\n", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("35.9 Hello \"%#.x %#.0x\"\n", 0, 0));
//
//		printf("Returned: %d\n", printf("35.10 Hello \"%#x %#x\"\n", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("35.10 Hello \"%#x %#x\"\n", 0, 0));
//
//        printf("Returned: %d\n", printf("35.10 Hello \"%5.x %5.0x\"\n", 0, 0));
//        printf("Returned: %d\n\n", ft_printf("35.10 Hello \"%5.x %5.0x\"\n", 0, 0));
//
//		printf("Returned: %d\n", printf("36 Hello \"%o\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("35 Hello \"%o\"\n", 42));
//
//		printf("Returned: %d\n", printf("36.1 Hello \"%O\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.1 Hello \"%O\"\n", 0));
//
//		printf("Returned: %d\n", printf("36.2 Hello \"%O\"\n", 4294967296));
//		printf("Returned: %d\n\n", ft_printf("35.2 Hello \"%O\"\n", 4294967296));
//
//		printf("Returned: %d\n", printf("36.3 Hello \"%10.5O\"\n", 1));
//		printf("Returned: %d\n\n", ft_printf("35.3 Hello \"%10.5O\"\n", 1));
//
//		printf("Returned: %d\n", printf("36.3 Hello \"% o|%+o\"\n", 42, 42));
//		printf("Returned: %d\n\n", ft_printf("35.3 Hello \"% o|%+o\"\n", 42, 42));
//
//		printf("Returned: %d\n", printf("36.4 Hello \"@moulitest: %5.o %5.0o\"\n", 0, 0));
//		printf("Returned: %d\n\n", ft_printf("35.4 Hello \"@moulitest: %5.o %5.0o\"\n", 0, 0));
//
//		printf("Returned: %d\n", printf("36.4 Hello \"@moulitest: %5c\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.4 Hello \"@moulitest: %5c\"\n", 0));
//
//		printf("Returned: %d\n", printf("36.4 Hello \"@moulitest: %.5c\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("35.4 Hello \"@moulitest: %.5c\"\n", 0));
//
//		printf("Returned: %d\n", printf("37 Hello \"%c\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("37 Hello \"%c\"\n", 42));
//
//		printf("Returned: %d\n", printf("37 Hello \"%c\"\n", 42));
//		printf("Returned: %d\n\n", ft_printf("37 Hello \"%c\"\n", 42));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%015C\"\n", L'ۊ'));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%015C\"\n", L'ۊ'));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%015C\"\n", L'~'));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%015C\"\n", L'~'));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%015C\"\n", L'暖'));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%015C\"\n", L'暖'));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%015C\"\n", 65));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%015C\"\n", 65));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%015C\"\n", L'🁏'));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%015C\"\n", L'🁏'));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%C\"\n", L'🁏'));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%C\"\n", L'🁏'));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%3c\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%3c\"\n", 0));
//
//		printf("Returned: %d\n", printf("18.1 Hello \"%c\"\n", 200));
//		printf("Returned: %d\n\n", ft_printf("18.1 Hello \"%c\"\n", 200));
//
//
//		printf("Returned: %d\n", printf("37 Hello \"%s\"\n", "fyyyyfyyyyfyyyyfyyyy"));
//		printf("Returned: %d\n\n", ft_printf("37 Hello \"%s\"\n", "fyyyyfyyyyfyyyyfyyyy"));
//
//        printf("Returned: %d\n", printf("37 Hello \"%s\"\n", "may the four be with two"));
//        printf("Returned: %d\n\n", ft_printf("37 Hello \"%s\"\n", "may the four be with two"));
//
//
//
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%.0s tut pustaia stroka\"\n", "42"));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%.0s tut pustaia stroka\"\n", "42"));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%.s tut pustaia stroka\"\n", "42"));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%.s tut pustaia stroka\"\n", "42"));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%.2s tut pustaia stroka\"\n", "42"));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%.2s tut pustaia stroka\"\n", "42"));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%.4s tut pustaia stroka\"\n", "42"));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%.4s tut pustaia stroka\"\n", "42"));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%.2s tut pustaia stroka\"\n", ""));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%.2s tut pustaia stroka\"\n", ""));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%20s tut pustaia stroka\"\n", ""));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%20s tut pustaia stroka\"\n", ""));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%10.5s tut pustaia stroka\"\n", ""));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%10.5s tut pustaia stroka\"\n", ""));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%5.10s tut pustaia stroka\"\n", ""));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%5.10s tut pustaia stroka\"\n", ""));
//
//		printf("Returned: %d\n", printf     ("37.1 Hello \"%50s   \"\n", "may the four be with two"));
//		printf("Returned: %d\n\n", ft_printf("37.1 Hello \"%50s   \"\n", "may the four be with two"));
//
//		printf("Returned: %d\n", printf     ("38.1 Hello \"%20S\"\n", L"may the four be with two"));
//		printf("Returned: %d\n\n", ft_printf("38.1 Hello \"%20S\"\n", L"may the four be with two"));
//
//		printf("Returned: %d\n", printf     ("37.1.1 Hello \"%3.15s   \"\n", "may the four be with two"));
//		printf("Returned: %d\n\n", ft_printf("37.1.1 Hello \"%3.15s   \"\n", "may the four be with two"));
//
//		printf("Returned: %d\n", printf     ("37.1.2 Hello \"%10s\"\n", "1111111"));
//		printf("Returned: %d\n\n", ft_printf("37.1.2 Hello \"%10s\"\n", "1111111"));
//
//		printf("Returned: %d\n", printf     ("37.1.2 Hello \"%10s is a string\"\n", "this   "));
//		printf("Returned: %d\n\n", ft_printf("37.1.2 Hello \"%10s is a string\"\n", "this   "));
//
//		printf("Returned: %d\n", printf     ("37.2 Hello \"%.2s   \"\n", "may the four be with two"));
//		printf("Returned: %d\n\n", ft_printf("37.2 Hello \"%.2s   \"\n", "may the four be with two"));
//
//        printf("Returned: %d\n", printf("38.1 Hello \"%S\"\n", L"~"));
//        printf("Returned: %d\n\n", ft_printf("38.1 Hello \"%S\"\n", L"~"));
//
//		printf("Returned: %d\n", printf("38.2 Hello \"%S\"\n", L"ۊ"));
//		printf("Returned: %d\n\n", ft_printf("38.2 Hello \"%S\"\n", L"ۊ"));
//
//		printf("Returned: %d\n", printf("38.3 Hello \"%S\"\n", L"α"));
//		printf("Returned: %d\n\n", ft_printf("38.3 Hello \"%S\"\n", L"α"));
//
//		printf("Returned: %d\n", printf("38.4 Hello \"%S\"\n", L"Ṅ"));
//		printf("Returned: %d\n\n", ft_printf("38.4 Hello \"%S\"\n", L"Ṅ"));
//
//		printf("Returned: %d\n", printf("38.4 Hello \"%S\"\n", L"🁏"));
//		printf("Returned: %d\n\n", ft_printf("38.4 Hello \"%S\"\n", L"🁏"));
//
//		printf("Returned: %d\n", printf("38.5 Hello \"%010S\"\n", L"米   "));
//		printf("Returned: %d\n\n", ft_printf("38.5 Hello \"%010S\"\n", L"米   "));
//
//		printf("Returned: %d\n", printf("%S", L"猫"));
//		printf("Returned: %d\n\n", ft_printf("%S", L"猫"));
//
//		printf("Returned: %d\n", printf("%S", L"我是一只猫。"));
//		printf("Returned: %d\n\n", ft_printf("%S", L"我是一只猫。"));
//
//		printf("Returned: %d\n", printf("38.5 Hello \"%S\"\n", L"我是一只猫。"));
//		printf("Returned: %d\n\n", ft_printf("38.5 Hello \"%S\"\n", L"我是一只猫。"));
//
//        printf("Returned: %d\n", printf("38.6 Hello \"%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\"\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
//                                             L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"", L"我"));
//        printf("Returned: %d\n\n", ft_printf("38.6 Hello \"%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S\"\n", L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
//                                                 L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"", L"我"));
//
//        printf("Returned: %d\n", printf("38.7 Hello \"a%Sb%sc%S\"\n", L"我", "42", L"猫"));
//        printf("Returned: %d\n\n", ft_printf("38.7 Hello \"a%Sb%sc%S\"\n", L"我", "42", L"猫"));
//
//        printf("Returned: %d\n", printf("38.8 Hello \"{%S}\"\n", NULL));
//        printf("Returned: %d\n\n", ft_printf("38.8 Hello \"{%S}\"\n", NULL));
//
//
//		printf("Returned: %d\n", printf("%ls, %ls", L"暖炉", L"لحم خنزير"));
//		printf("Returned: %d\n\n", ft_printf("%ls, %ls", L"暖炉", L"لحم خنزير"));
//
//		printf("Returned: %d\n", printf("39 Hello \"%C\"\n", 'c'));
//		printf("Returned: %d\n\n", ft_printf("39 Hello \"%C\"\n", 'c'));
//
//		printf("Returned: %d\n", printf("39 Hello \"%C\"\n", L'是'));
//		printf("Returned: %d\n\n", ft_printf("39 Hello \"%C\"\n", L'是'));
//
//		printf("Returned: %d\n", printf("39 Hello \"%C\"\n", 0));
//		printf("Returned: %d\n\n", ft_printf("39 Hello \"%C\"\n", 0));
//		char c = 99;
//		printf("Returned: %d\n", printf     ("%d%p%S%D%i  %o%O", 42, &c, L"暖炉", LONG_MAX, 42, 42));
//        printf("Returned: %d\n\n", ft_printf("%d%p%S%D%i  %o%O", 42, &c, L"暖炉", LONG_MAX, 42, 42));
//
//		printf("Returned: %d\n", printf("40 Hello \"%D%u%U\"\n", LONG_MAX, 100000, ULONG_MAX));
//		printf("Returned: %d\n", ft_printf("40 Hello \"%D%u%U\"\n", LONG_MAX, 100000, ULONG_MAX));
//
//		printf("Returned: %d\n", printf("40 Hello \"%s %C %d %p %x %% %S\"\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//		printf("Returned: %d\n", ft_printf("40 Hello \"%s %C %d %p %x %% %S\"\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير"));
//
//		printf("Returned: %d\n", printf("40 Hello \"%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\"\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//		printf("Returned: %d\n", ft_printf("40 Hello \"%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\"\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//
//		printf   ("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
//		ft_printf("%s %C %d %p %x %% %S\n", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
//
//		printf("Returned: %d\n", printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));
//		printf("Returned: %d\n", ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플'));


		//    printf("\nIteration %d\n",i);
    }
	return (0);
}
