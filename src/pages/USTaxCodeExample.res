open PageComponents

let pageTitle = <Lang.String english="US Tax Code" french=`Code des impôts américain` />

let card: Card.Presentation.t = {
  title: pageTitle,
  action: Some((
    Internal([Nav.home, Nav.examples, Nav.usTaxCode]),
    <Lang.String english="See example" french=`Voir l'exemple` />,
  )),
  icon: None,
  quote: None,
  content: <>
    <Lang.String
      english="The content of this example is generated by the Catala compiler from the "
      french=`Le contenu de cet exemple est généré par le compilateur de Catala à partir des `
    />
    <Link.Text target="https://github.com/CatalaLang/catala/tree/master/examples/us_tax_code">
      <Lang.String
        english="source code files of the example" french=`fichiers source de l'exemple`
      />
    </Link.Text>
    {"."->React.string}
  </>,
}

@react.component
let make = () => <>
  <Title> pageTitle </Title>
  <p className=%twc("pb-16")>
    <Lang.String
      english="The source code for this example is available "
      french=`Le code source de cet exemple est disponible `
    />
    <Link.Text target="https://github.com/CatalaLang/catala/tree/master/examples/us_tax_code">
      <Lang.String english="here" french=`ici` />
    </Link.Text>
    <Lang.String
      english=". What you can see here is the \"weaved\" output of the source files processed by the Catala compiler.
        Weaving is a concept from "
      french=`. Ce que vous pouvez voir en dessous est la version "tissée" des fichiers sources transformés par le compilateur Catala.
        Le tissage est un concept issu de la `
    />
    <Link.Text target="https://en.wikipedia.org/wiki/Literate_programming#Workflow">
      <Lang.String english="literate programming" french=`programmation littéraire` />
    </Link.Text>
    <Lang.String
      english=" corresponding to the action of interleaving together the code and its textual documentation
         as to produce a reviewable and comprehensive document. Please refer to the tutorial for a hands-on introduction
          on how to read this document."
      french=` , qui correspond à l'action d'entremêler le code et sa documentation textuelle dans un document
         complet et lisible. Veuillez vous réferer au tutoriel pour savoir comment lire ce document.`
    />
  </p>
  <CatalaCode.DangerouslySetInnerHtml html=%raw(`require("../../assets/us_tax_code.html")`) />
</>
